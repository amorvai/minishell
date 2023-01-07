/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:24:46 by amorvai           #+#    #+#             */
/*   Updated: 2022/12/13 12:07:42 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**free_splits(char **splits)
{
	size_t	i;

	i = 0;
	while (splits && splits[i])
	{
		free(splits[i]);
		splits[i] = NULL;
		i++;
	}
	if (splits)
	{
		free(splits);
		splits = NULL;
	}
	return (NULL);
}

static size_t	no_of_splits(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s[i] == '\0')
		return (j);
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i] == c && s[i] != '\0')
		{
			while (s[i] == c && s[i] != '\0')
				i++;
			j++;
		}
	}
	return (j + 1);
}

static char	**real_split(const char *s, char c, char **splits)
{
	size_t	i;
	size_t	j;
	size_t	l;

	i = 0;
	l = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		if (j > 0)
		{
			splits[l] = ft_substr(s, i, j);
			if (splits[l] == NULL)
				return (free_splits(splits));
			l++;
		}
		if (s[i + j] != '\0')
			j++;
		i = i + j;
	}
	return (splits);
}

char	**ft_split(const char *s, char c)
{
	char	**splits;

	if (!s)
		return (NULL);
	splits = ft_calloc(no_of_splits(s, c) + 1, sizeof(char *));
	if (splits == NULL)
		return (NULL);
	return (real_split(s, c, splits));
}
