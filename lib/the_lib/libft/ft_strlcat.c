/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:42:12 by amorvai           #+#    #+#             */
/*   Updated: 2022/03/31 14:46:25 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
	{
		if (dstsize == 0)
			return (i + ft_strlen(src));
		i++;
		dstsize--;
	}
	while (dstsize > 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
		dstsize--;
	}
	if (dstsize == 1 || src[j] == '\0')
		dst[i] = '\0';
	while (src[j] != '\0' && ++j && ++i)
		;
	return (i);
}
