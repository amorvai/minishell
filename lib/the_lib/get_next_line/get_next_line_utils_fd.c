/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:01:05 by amorvai           #+#    #+#             */
/*   Updated: 2022/09/17 20:40:51 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_fd.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

ssize_t	ft_strlen_mod(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	if (c == '\0')
		return (i);
	return (-1);
}

void	*ft_memset(void *str, int c, size_t len)
{
	size_t	i;
	char	*s;

	i = 0;
	s = str;
	while (i < len)
	{
		s[i] = c;
		i++;
	}
	return (str);
}

char	*ft_substr_(const char *s, unsigned int start, ssize_t len)
{
	char	*substr;
	ssize_t	i;

	if (s == NULL)
		return (NULL);
	substr = malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (len > i && (ssize_t)start < ft_strlen_mod(s, '\0'))
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
