/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:02:06 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/10 13:09:06 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/the_lib/lib.h" //for calloc
#include "token.h"
#include <stdio.h>

void	get_token_enum(const char *s, size_t i, size_t j, t_token *new_token)
{
	if (s[i] == '|')
		new_token->token = PIPE;
	else if (s[i] == '<')
	{
		new_token->token = LESS;
		if (s[i + 1] == '<')
			new_token->token = LLESS;
	}
	else if (s[i] == '>')
	{
		new_token->token = GREAT;
		if (s[i + 1] == '>')
			new_token->token = GGREAT;
	}
	else
	{
		new_token->token = WORD;
		new_token->word = ft_substr(s, i, j);
	}
}

void	init_token_to_list(t_token **token_lst, const char *s,
							size_t *i, size_t *j)
{
	t_token	*new_token;

	if (*j == 0)
		return ;
	new_token = ft_calloc(1, sizeof(t_token));
	// what to fail
	get_token_enum(s, *i, *j, new_token);
	if (new_token->token == GGREAT || new_token->token == LLESS)
		(*j)++;
	*i = *i + *j;
	*j = 0;
	tokenadd_back(token_lst, new_token);
}

int	token_quote(const char *s, size_t *i, size_t *j, char quote_type)
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

static int	token_detected(t_token **token_lst, const char *s, size_t *i)
{
	size_t	j;

	j = 0;
	while (s[*i + j] != '\0' && !ft_strchr(" \t\n", s[*i + j]))
	{
		if (ft_strchr("|<>", s[*i + j]))
		{
			if (*i + j > 0 && !ft_strchr(" \t\n", s[*i + j - 1]))
				init_token_to_list(token_lst, s, i, &j);
			j++;
			break ;
		}
		if (s[*i + j] == '"' && token_quote(s, i, &j, '"'))
			return (1);
		else if (s[*i + j] == '\'' && token_quote(s, i, &j, '\''))
			return (1);
		j++;
	}
	init_token_to_list(token_lst, s, i, &j);
	return (0);
}

int	token_lst_init(t_token **token_lst, const char *s)
{
	size_t	i;

	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && ft_strchr(" \t\n", s[i]))
			i++;
		if (s[i] == '\0')
			break ;
		if (token_detected(token_lst, s, &i))
			return (1);
	}
	return (0);
}
