/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:22:55 by amorvai           #+#    #+#             */
/*   Updated: 2022/05/07 19:22:20 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	d;

	d = (char )c;
	i = 0;
	while (s[i] != d && s[i] != '\0')
		i++;
	if (s[i] == d)
	{
		s += i;
		return ((char *)s);
	}
	return (NULL);
}
