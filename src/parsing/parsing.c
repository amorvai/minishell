/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:58:08 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/18 12:57:03 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"
#include "../structure/command.h"
#include "../structure/redirection.h"
#include "../../lib/the_lib/lib.h"
// GIMME THE LOOT

// int	get_redirections(t_token **token_lst, t_simp_com *curr_command)
// {
// 	t_token			*temp_lst;
// 	t_redirection	*new_redir;
//
// 	temp_lst = *token_lst;
// 	// if (token_lst && temp_lst && temp_lst->token == PIPE)
// 	// 	return (1); // syntax error near '|'
// 	while (token_lst && temp_lst && temp_lst->token != PIPE)
// 	{
// 		if (temp_lst->token > 1)
// 		{
// 			if (!temp_lst->next || temp_lst->next->token != WORD)
// 				return (1); // syntax error near 'enum e_token'
// 			new_redir = extract_redirection(temp_lst);
// 			if (temp_lst->token % 2)
// 				redir_add_back(&curr_command->redirect_input, new_redir);
// 			else
// 				redir_add_back(&curr_command->redirect_output, new_redir);
// 			token_delete(token_lst, temp_lst->next);
// 			token_delete(token_lst, temp_lst);
// 			temp_lst = *token_lst;
// 			// token_lst_print(temp_lst);
// 			continue ;
// 		}
// 		temp_lst = temp_lst->next;
// 	}
// 	// if (token_lst && temp_lst && temp_lst->token == PIPE && !temp_lst->next)
// 	// 	return (1); // syntax error near '|'
// 	return (0);
// }

// int	get_rest(t_token **token_lst, t_simp_com *curr_command)
// {
// 	t_token	*temp_lst;
// 	int		i;
//
// 	temp_lst = *token_lst;
// 	i = 0;
// 	while (token_lst && temp_lst && temp_lst->token != PIPE)
// 	{
// 		temp_lst = temp_lst->next;
// 		i++;
// 	}
// 	curr_command->command = ft_calloc(i + 1, sizeof(char *));
// 	i = 0;
// 	// print_commands(curr_command);
// 	while (token_lst && (*token_lst) && (*token_lst)->token != PIPE)
// 	{
// 		// printf("str: %s\n", (*token_lst)->word);
// 		curr_command->command[i] = expand_token((*token_lst)->word);
// 		token_delete(token_lst, *token_lst);
// 		i++;
// 	}
// 	if (token_lst && (*token_lst) && (*token_lst)->token == PIPE)
// 		token_delete(token_lst, *token_lst);
// 	return (0);
// }

// t_simp_com	*get_simp_command(t_token **token_lst)
// {
// 	t_simp_com	*curr_command;
//
// 	curr_command = ft_calloc(1, sizeof(t_simp_com));
// 	if (get_redirections(token_lst, curr_command))
// 		return (NULL);
// 	if (get_rest(token_lst, curr_command))
// 		return (NULL);
// 	return (curr_command);
// }

// t_simp_com	*parse_for_commands(t_token **token_lst)
// {
// 	t_simp_com	*head_command;
// 	t_simp_com	*curr_command;
//
// 	head_command = NULL;
// 	while (*token_lst)
// 	{
// 		curr_command = get_simp_command(token_lst);
// 		if (!curr_command)
// 		{
// 			command_lst_clear(&head_command);
// 			return (NULL);
// 		}
// 		command_lst_add_back(&head_command, curr_command);
// 	}
// 	return (head_command);
// }

static int	command_count(t_token *current)
{
	int count;

	count = 0;
	while (current)
	{
		if (current->token == PIPE)
			count++;
		current = current->next;
	}
	return (count + 1);
}

static t_token	*split_token_list(t_token **token_lst, t_token *split_point)
{
	t_token *first_part = *token_lst;
	*token_lst = split_point;
	if (split_point)
	{
		split_point->prev->next = NULL;
		split_point->prev = NULL;
	}
	return first_part;
}

static t_token	**organize_tokens_by_pipes(t_token **token_lst, int nb_commands)
{
	t_token	**token_per_command;
	t_token	*it;
	int		i;

	token_per_command = ft_calloc(nb_commands + 1, sizeof(t_token *));
	i = 0;
	while (i < nb_commands)
	{
		it = *token_lst;
		while (it && it->token != PIPE)
			it = it->next;
		if (it != *token_lst)
			token_per_command[i] = split_token_list(token_lst, it);
		if (*token_lst && (*token_lst)->token == PIPE)
			token_delete(token_lst, *token_lst);
		i++;
	}
	// if (*token_lst == NULL) //
	// 	ft_printf("organize tokens worked (token_lst is clear)\n"); //
	return (token_per_command);
}

static int	get_simple_command(t_token *token_lst, t_token *next_lst, t_simp_com **head_command)
{
	t_simp_com	*curr_command;
	const t_token a = {.token = PIPE, .word = NULL, .prev = NULL, .next = NULL};

	if (!token_lst)
		return (print_syntax_error(&a), 1); //syntax error near '|'
	curr_command = ft_calloc(1, sizeof(t_simp_com));
	if (extract_redirections(token_lst, next_lst, curr_command))
	{
		command_lst_clear(&curr_command);
		return (1);
	}
	extract_command(token_lst, curr_command);
	command_lst_add_back(head_command, curr_command);
	return (0);
}

int	parse(t_token **token_lst, t_simp_com **head_command)
{
	t_token	**token_per_command;
	int		nb_commands;
	int		i;

	nb_commands = command_count(*token_lst);
	token_per_command = organize_tokens_by_pipes(token_lst, nb_commands);
	i = 0;
	while (i < nb_commands)
	{
		// ft_printf("token_per_command[%i]:\n", i); //
		// token_lst_print(token_per_command[i]); //
		if (get_simple_command(token_per_command[i], token_per_command[i + 1], head_command))
		{
			command_lst_clear(head_command);
			free_token_lst_array(token_per_command, nb_commands);
			return (1);
		}
		i++;
	}
	free_token_lst_array(token_per_command, nb_commands);
	// ft_printf("\noriginal token_lst:\n"); //
	// token_lst_print(*token_lst); //
	return (0);
}
