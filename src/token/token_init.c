/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:02:06 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/16 22:08:32 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/the_lib/lib.h" //for calloc
#include "token.h"
#include <stdio.h>

void	get_token_enum(const char *s, size_t *i, t_token *new_token)
{
	if (s[*i] == '|')
		new_token->token = PIPE;
	else if (s[*i] == '<')
	{
		new_token->token = LESS;
		if (s[*i + 1] == '<')
			new_token->token = LLESS;
	}
	else if (s[*i] == '>')
	{
		new_token->token = GREAT;
		if (s[*i + 1] == '>')
			new_token->token = GGREAT;
	}
}

void	init_token_to_list(t_token **tokens, const char *s,
							size_t *i, size_t *j)
{
	t_token	*new_token;

	if (*j == 0)
		return ;
	new_token = ft_calloc(1, sizeof(t_token));
	// what to fail
	if (*j > 1)
	{
		new_token->token = WORD;
		new_token->word = ft_substr(s, *i, *j);
	}
	else
		get_token_enum(s, i, new_token);
	if (new_token->token == GGREAT || new_token->token == LLESS)
		(*j)++;
	*i = *i + *j;
	*j = 0;
	tokenadd_back(tokens, new_token);
}

static int	token_quote(const char *s, size_t *i, size_t *j, char quote_type)
{
	(*j)++;
	while (s[*i + *j] != quote_type)
	{
		if (s[*i + *j] == '\0')
			return (1);
		(*j)++;
	}
	return (0);
}

static int	token_detected(t_token **tokens, const char *s, size_t *i)
{
	size_t	j;

	j = 0;
	while (s[*i + j] != '\0'
		&& s[*i + j] != ' ' && s[*i + j] != '\t' && s[*i + j] != '\n')
	{
		if (s[*i + j] == '|' || s[*i + j] == '<' || s[*i + j] == '>')
		{
			if (*i + j > 0 && s[*i + j - 1] != ' '
				&& s[*i + j - 1] != '\t' && s[*i + j - 1] != '\n')
				init_token_to_list(tokens, s, i, &j);
			j++;
			break ;
		}
		if (s[*i + j] == '"' && token_quote(s, i, &j, '"'))
			return (1);
		else if (s[*i + j] == '\'' && token_quote(s, i, &j, '\''))
			return (1);
		j++;
	}
	init_token_to_list(tokens, s, i, &j);
	return (0);
}

int	tokens_init(t_token **tokens, const char *s)
{
	size_t	i;

	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		if (s[i] == '\0')
			break ;
		if (token_detected(tokens, s, &i))
			return (1);
	}
	return (0);
}
