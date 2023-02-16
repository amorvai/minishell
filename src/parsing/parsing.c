/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:58:08 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/16 10:28:36 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../structure/command.h"
#include "../structure/redirection.h"
#include "../../lib/the_lib/lib.h"
// GIMME THE LOOT

void	append_str(char **command_str, char *str, size_t start, size_t len)
{
	char	*new_command_str;
	char	*append;
	size_t	len_old;

	append = str + start;
	if (*command_str)
		len_old = ft_strlen(*command_str);
	else
		len_old = 0;
	new_command_str = ft_calloc(len_old + len + 1, sizeof(char));
	ft_memcpy(new_command_str, *command_str, len_old);
	ft_strlcat(new_command_str, append, len_old + len + 1);
	if (*command_str)
		free(*command_str);
	*command_str = new_command_str;
}

int	get_redirections(t_token **token_lst, t_simp_com *curr_command)
{
	t_token			*temp_lst;
	t_redirection	*new_redir;

	temp_lst = *token_lst;
	// if (token_lst && temp_lst && temp_lst->token == PIPE)
	// 	return (1); // syntax error near '|'
	while (token_lst && temp_lst && temp_lst->token != PIPE)
	{
		if (temp_lst->token > 1)
		{
			if (!temp_lst->next || temp_lst->next->token != WORD)
				return (1); // syntax error near 'enum e_token'
			new_redir = extract_redirection(temp_lst);
			if (temp_lst->token % 2)
				redir_add_back(&curr_command->redirect_input, new_redir);
			else
				redir_add_back(&curr_command->redirect_output, new_redir);
			token_delete(token_lst, temp_lst->next);
			token_delete(token_lst, temp_lst);
			temp_lst = *token_lst;
			// token_lst_print(temp_lst);
			continue ;
		}
		temp_lst = temp_lst->next;
	}
	// if (token_lst && temp_lst && temp_lst->token == PIPE && !temp_lst->next)
	// 	return (1); // syntax error near '|'
	return (0);
}

int	get_rest(t_token **token_lst, t_simp_com *curr_command)
{
	t_token	*temp_lst;
	int		i;

	temp_lst = *token_lst;
	i = 0;
	while (token_lst && temp_lst && temp_lst->token != PIPE)
	{
		temp_lst = temp_lst->next;
		i++;
	}
	curr_command->command = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	// print_commands(curr_command);
	while (token_lst && (*token_lst) && (*token_lst)->token != PIPE)
	{
		// printf("str: %s\n", (*token_lst)->word);
		curr_command->command[i] = expand_token((*token_lst)->word);
		token_delete(token_lst, *token_lst);
		i++;
	}
	if (token_lst && (*token_lst) && (*token_lst)->token == PIPE)
		token_delete(token_lst, *token_lst);
	return (0);
}

t_simp_com	*get_simp_command(t_token **token_lst)
{
	t_simp_com	*curr_command;

	curr_command = ft_calloc(1, sizeof(t_simp_com));
	if (get_redirections(token_lst, curr_command))
		return (NULL);
	if (get_rest(token_lst, curr_command))
		return (NULL);
	return (curr_command);
}

t_simp_com	*parse_for_commands(t_token **token_lst)
{
	t_simp_com	*head_command;
	t_simp_com	*curr_command;

	head_command = NULL;
	while (*token_lst)
	{
		curr_command = get_simp_command(token_lst);
		if (!curr_command)
		{
			command_lst_clear(&head_command);
			return (NULL);
		}
		command_lst_add_back(&head_command, curr_command);
	}
	return (head_command);
}
