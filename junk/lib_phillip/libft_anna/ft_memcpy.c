/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:47:33 by amorvai           #+#    #+#             */
/*   Updated: 2022/04/29 17:20:17 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst2;
	const char	*src2;
	size_t		i;

	dst2 = dst;
	src2 = src;
	i = 0;
	while (i < n && (dst != NULL || src != NULL))
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}
