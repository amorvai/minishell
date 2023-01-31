/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:58:08 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/31 18:33:24 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// GIMME THE LOOT

char	*expand_token(char *str)
{
	char	command_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i + j] != '\0')
	{
		// if (str[i + j] != '\'')
		// 	token_quote(str, &i, &j, '\'');
		if (ft_strchr("\'\"$", str[i + j]))
		{
			append_str(command_str, str, i, j);
			if (ft_strchr("\'\"", str[i + j]))
			{
				
			}
		}
		j++;
	}
	if (j > 0)
		append_str(command_str, str, i, j);
	return (command_str);
}

int	get_redirections(t_token **token_lst, t_simp_com *curr_command);

int	get_simp_command(t_token **token_lst, t_simp_com *curr_command)
{
	int	i;

	i = 0;
	if (get_redirections(token_lst, curr_command))
		return (1);
	while (token_lst && (*token_lst) && (*token_lst)->token != PIPE)
	{
		curr_command->command[i] = expand_token((*token_lst)->word);
		token_delete(token_lst, *token_lst);
		i++;
	}
	if (token_lst && (*token_lst) && (*token_lst)->token == PIPE)
		token_delete(token_lst, *token_lst);
	return (0);
}

t_simp_com	*parse(t_token **token_lst)
{
	t_simp_com	*head_command;
	t_simp_com	*curr_command;

	while (*token_lst)
	{
		if (get_simp_command(token_lst, curr_command))
		{
			free_command_list();
			return (NULL);
		}
		command_add_back(&head_command, curr_command);
	}
	return (head_command);
}
