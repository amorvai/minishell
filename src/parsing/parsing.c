/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:58:08 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/21 17:37:26 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"
#include "../structure/command.h"
#include "../structure/redirection.h"
#include "../../lib/the_lib/lib.h"

static int	command_count(t_token *current)
{
	int	count;

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
	t_token	*first_part;

	first_part = *token_lst;
	*token_lst = split_point;
	if (split_point)
	{
		split_point->prev->next = NULL;
		split_point->prev = NULL;
	}
	return (first_part);
}

static t_token	**organize_tokens_by_pipes(t_token **token_lst, int nb_commands)
{
	t_token	**token_per_command;
	t_token	*it;
	int		i;

	token_per_command = ft_xcalloc(nb_commands + 1, sizeof(t_token *));
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
	return (token_per_command);
}

static int	get_simple_command(t_token *token_lst, t_token *next_lst,
								t_simp_com **head_command)
{
	t_simp_com		*curr_command;
	const t_token	a
		= {.token = PIPE, .word = NULL, .prev = NULL, .next = NULL};

	if (!token_lst)
		return (print_syntax_error(&a), 1);
	curr_command = ft_xcalloc(1, sizeof(t_simp_com));
	if (extract_redirections(token_lst, next_lst, curr_command))
	{
		command_lst_clear(&curr_command);
		return (1);
	}
	extract_command(token_lst, curr_command);
	command_lst_add_back(head_command, curr_command);
	return (0);
}

int	parse(t_token **orig_token_lst, t_simp_com **head_command)
{
	t_token	**token_lsts;
	int		nb_commands;
	int		i;

	nb_commands = command_count(*orig_token_lst);
	token_lsts = organize_tokens_by_pipes(orig_token_lst, nb_commands);
	i = 0;
	while (i < nb_commands)
	{
		if (get_simple_command(token_lsts[i], token_lsts[i + 1], head_command))
		{
			command_lst_clear(head_command);
			free_token_lst_array(token_lsts, nb_commands);
			return (1);
		}
		i++;
	}
	free_token_lst_array(token_lsts, nb_commands);
	return (0);
}
