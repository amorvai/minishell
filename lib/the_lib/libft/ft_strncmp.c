/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:53:17 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/20 23:38:24 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	t;

	t = 0;
	if (n == 0)
		return (0);
	while (s1[t] == s2[t] && t < n)
	{
		if (s1[t] == '\0' && s2[t] == '\0')
			return (0);
		t++;
	}
	if (t != n)
	{
		s1 += t;
		s2 += t;
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	t;

	t = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	else if (s1 == NULL)
		return (*(unsigned char *)s2);
	else if (s2 == NULL)
		return (*(unsigned char *)s1);
	while (s1[t] == s2[t])
	{
		if (s1[t] == '\0' && s2[t] == '\0')
			return (0);
		t++;
	}
	s1 += t;
	s2 += t;
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
