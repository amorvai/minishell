/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:23:38 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/18 12:51:24 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "expansion.h"
#include "../token/token.h"
#include "../structure/redirection.h"
#include "../structure/command.h"
#include "../../lib/the_lib/lib.h"
#include <stdbool.h>

static int	is_redirection_input(enum e_token token_type)
{
	if (token_type == LESS)
		return true;
	if (token_type == LLESS)
		return true;
	return false;
}

static int	is_redirection_output(enum e_token token_type)
{
	if (token_type == GREAT)
		return true;
	if (token_type == GGREAT)
		return true;
	return false;
}

int	is_redirection(enum e_token token_type)
{
	if (is_redirection_input(token_type))
		return true;
	if (is_redirection_output(token_type))
		return true;
	return false;
}

int	extract_redirections(t_token *it, t_token *next_lst, t_simp_com *command)
{
	t_redirection	*new_redirection;
	const t_token a = {.token = PIPE, .word = NULL, .prev = NULL, .next = NULL};

	while (it)
	{
		if (is_redirection(it->token))
		{
			if (it->next != NULL && it->next->token != WORD)
				return (print_syntax_error(it->next), 1); // syntax error near '[it->next(->token)]' (if NULL then 'newline') // actually issue bc I split for commands
			if (it->next == NULL && next_lst)
				return (print_syntax_error(NULL), 1); // syntax error near '[it->next(->token)]' (if NULL then 'newline') // actually issue bc I split for commands
			if (it->next == NULL && !next_lst)
				return (print_syntax_error(&a), 1); // syntax error near 'PIPE'
			new_redirection = ft_calloc(1, sizeof(t_redirection));
			if (is_redirection_input(it->token)) 
				redir_add_back(&command->redirect_input, new_redirection);
			else
				redir_add_back(&command->redirect_output, new_redirection);
			new_redirection->redir_type = it->token;
			new_redirection->file = expand_token(it->next->word);
		}
		it = it->next;
	}
	return (0);
}

// int	extract_redirections(t_token **it, t_simp_com *command)
// {
// 	while (*it && (*it)->token != PIPE)
// 	{
// 		if (is_redirection((*it)->token))
// 		{
// 			if ((*it)->next == NULL)
// 				return (1); // syntax error near 'newline'
// 			if ((*it)->next->token != WORD)
// 				return (1); // syntax error near '[(*it)->next->token]' // kann man auch wieder zusammenfassen
// 			t_redirection *new_redirection = (t_redirection *)malloc(sizeof(t_redirection));
// 			if (is_redirection_input((*it)->token)) 
// 				token_list_push_back(command->redirect_input, new_redirection);
// 			else
// 				token_list_push_back(command->redirect_output, new_redirection);
// 			new_redirection->redir_type = (*it)->token;
// 			new_redirection->file = expand_token((*it)->next->word);
// 		}
// 		*it = (*it)->next;
// 	}
// 	if (*it && (*it)->token == PIPE && !(*it)->next)
// 		return (1); // syntax error near 'newline'
// 	if (*it && (*it)->token == PIPE)
// 		*it = (*it)->next;
// 	return (0);
// }
