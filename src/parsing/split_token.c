/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:24:46 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/07 10:24:04 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/the_lib/lib.h"
#include <stdio.h>

int	token_quote(const char *s, size_t *i)
{
	(*i)++;
	while (s[*i] != '"')
	{
		if (s[*i] == '\0')
			return (1);
		(*i)++;
	}
	return (0);
}

int	no_of_tokens(const char *s, int *tokens)
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
		while (s[i] != ' ')
		{
			if (s[i] == '"' && token_quote(s, &i))
				return (1);
			i++;
		}
		(*tokens)++;
	}
	return (0);
}

// int main()
// {
// 	int token;
// 	token = 0;
// 	printf("no_of_splits(hello \" echo\" ec\"ho\" \"echo \"     \" echo \" what up boys i" " certainly \"agree\")\nreturn value: %i\n# of tokens: %i\n",\
// 			 no_of_tokens("hello \" echo\" ec\"ho\" \"echo \"     \" echo \" what up boys i" " certainly \"agree\"", &token), token);
// 	return (0);
// }

static char	**real_token(const char *s, char **splits)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == ' ')
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != ' ')
		{
			if (s[i] == '"' && token_quote(s, &i))
				return (1);
			i++;
		}
	}
	return (0);
}

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

char	**ft_token(const char *s)
{
	char	**tokens;
	int		no_of_token;

	if (!s)
		return (NULL);
	if (no_of_tokens(s, &no_of_token))
		return (NULL);
	tokens = ft_calloc(no_of_token + 1, sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	return (real_token(s, tokens));
}
