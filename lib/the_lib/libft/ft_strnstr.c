/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:17:27 by amorvai           #+#    #+#             */
/*   Updated: 2022/05/23 23:38:45 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while (i < len && haystack[i] != '\0' && haystack[i] != needle[j])
			i++;
		if (haystack[i] == '\0')
			return (NULL);
		while ((i + j) < len && needle[j] != '\0'
			&& haystack[i + j] == needle[j])
		{
			if (needle[++j] == '\0')
			{
				haystack += i;
				return ((char *)haystack);
			}
		}
		i++;
	}
	return (NULL);
}
