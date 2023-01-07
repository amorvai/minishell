/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:42:21 by amorvai           #+#    #+#             */
/*   Updated: 2022/05/13 15:41:50 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int b, size_t n)
{
	const unsigned char	*t;
	unsigned char		c;
	size_t				i;

	c = (unsigned char )b;
	t = (const unsigned char *)s;
	i = 0;
	while (i < n && t[i] != c)
		i++;
	if (i < n && t[i] == c)
	{
		t += i;
		return ((unsigned char *)t);
	}
	return (NULL);
}
