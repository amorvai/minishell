/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:24:46 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/16 21:18:14 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/the_lib/lib.h"
#include "parsing.h"
#include <stdio.h>

static int	token_quote(const char *s, size_t *i, char quote_type)
{
	(*i)++;
	while (s[*i] != quote_type)
	{
		if (s[*i] == '\0')
			return (1);
		(*i)++;
	}
	return (0);
}

static int	token_detected(const char *s, int *nb_tokens, size_t *i)
{
	while (s[*i] != '\0' && s[*i] != ' ')
	{
		if (s[*i] == '|')
		{
			if (*i > 0 && s[*i - 1] != ' ')
				(*nb_tokens)++;
			(*i)++;
			break ;
		}
		if (s[*i] == '"' && token_quote(s, i, '"'))
			return (1);
		else if (s[*i] == '\'' && token_quote(s, i, '\''))
			return (1);
		(*i)++;
	}
	return (0);
}

int	no_of_tokens(const char *s, int *nb_tokens)
{
	size_t	i;

	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == ' ')
			i++;
		if (s[i] == '\0')
			break ;
		if (token_detected(s, nb_tokens, &i))
			return (1);
		(*nb_tokens)++;
	}
	return (0);
}

int	add_token(t_token **head, char *s, int *i)
{
	t_token	*new;
	int		token_len;

	// new = ft_calloc(1, sizeof(t_token));
	// while ()
}

t_token **get_tokens(char *s)
{
	t_token	*head;
	size_t	i;

	i = 0;
	head = NULL;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		if (s[i] == '\0')
			break ;
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			if (add_token(&head, s, &i))
				return (free_tokens(head), NULL);
	}
	return (&head);
}

// static char	**real_token(const char *s, char **splits)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		while (s[i] == ' ')
// 			i++;
// 		if (s[i] == '\0')
// 			break ;
// 		while (s[i] != ' ')
// 		{
// 			if (s[i] == '"' && token_quote(s, &i))
// 				return (1);
// 			i++;
// 		}
// 	}
// 	return (0);
// }

// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	l;

// 	i = 0;
// 	l = 0;
// 	while (s[i] != '\0')
// 	{
// 		j = 0;
// 		while (s[i + j] != c && s[i + j] != '\0')
// 			j++;
// 		if (j > 0)
// 		{
// 			splits[l] = ft_substr(s, i, j);
// 			if (splits[l] == NULL)
// 				return (free_splits(splits));
// 			l++;
// 		}
// 		if (s[i + j] != '\0')
// 			j++;
// 		i = i + j;
// 	}
// 	return (splits);
// }

t_token	**ft_token_raw(const char *s)
{
	t_token	**tokens;
	int		no_of_token;

	if (!s)
		return (NULL);
	if (no_of_tokens(tokens, s, &no_of_token))
		return (NULL);
	return (tokens);
}
