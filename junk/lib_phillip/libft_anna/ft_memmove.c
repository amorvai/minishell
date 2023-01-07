/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:47:33 by amorvai           #+#    #+#             */
/*   Updated: 2022/04/28 20:07:30 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst2;
	const char	*src2;
	size_t		i;

	dst2 = dst;
	src2 = src;
	i = 0;
	if (dst2 < src2)
	{
		while (i < len && (dst != NULL || src != NULL))
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	else
	{
		while (i < len && (dst != NULL || src != NULL))
		{
			dst2[len - 1] = src2[len - 1];
			len--;
		}
	}
	return (dst);
}
