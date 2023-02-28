/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:23:38 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/28 09:43:01 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "../heredoc/heredoc.h"
#include "../token/token.h"
#include "../structure/command.h"
#include "../structure/redirection.h"
#include "../error/error.h"
#include "../../lib/the_lib/lib.h"

#include <stdbool.h>

static int	is_redirection_input(enum e_token token_type)
{
	if (token_type == LESS)
		return (true);
	if (token_type == LLESS)
		return (true);
	return (false);
}

static int	is_redirection_output(enum e_token token_type)
{
	if (token_type == GREAT)
		return (true);
	if (token_type == GGREAT)
		return (true);
	return (false);
}

int	is_redirection(enum e_token token_type)
{
	if (is_redirection_input(token_type))
		return (true);
	if (is_redirection_output(token_type))
		return (true);
	return (false);
}

void	add_redirection(enum e_token type, const char *file,
	t_redirection **redirection)
{
	t_redirection	*new_redirection;

	new_redirection = ft_xcalloc(1, sizeof(t_redirection));
	new_redirection->redir_type = type;
	if (type != LLESS)
		new_redirection->file = expand_token(file);
	else
		new_redirection->file = heredoc(file);
	redir_add_back(redirection, new_redirection);
}

int	extract_redirections(t_token *it, t_token *next_lst, t_simp_com *command)
{
	const t_token	a
		= {.token = PIPE, .word = NULL, .prev = NULL, .next = NULL};

	while (it)
	{
		if (is_redirection(it->token))
		{
			if (it->next != NULL && it->next->token != WORD)
				return (print_syntax_error(it->next), 1);
			if (it->next == NULL && !next_lst)
				return (print_syntax_error(NULL), 1);
			if (it->next == NULL && next_lst)
				return (print_syntax_error(&a), 1);
			if (is_redirection_input(it->token))
				add_redirection(it->token, it->next->word,
					&command->redirect_input);
			else
				add_redirection(it->token, it->next->word,
					&command->redirect_output);
		}
		it = it->next;
	}
	return (0);
}
