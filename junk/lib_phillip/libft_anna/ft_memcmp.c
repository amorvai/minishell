/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:24:00 by amorvai           #+#    #+#             */
/*   Updated: 2022/03/31 14:47:04 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		t;
	const char	*f1;
	const char	*f2;

	t = 0;
	f1 = (const char *)s1;
	f2 = (const char *)s2;
	if (n == 0)
		return (0);
	while (t < n && f1[t] == f2[t])
		t++;
	if (t != n)
	{
		s1 += t;
		s2 += t;
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
	return (0);
}
