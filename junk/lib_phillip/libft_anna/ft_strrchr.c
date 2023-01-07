/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:21:36 by amorvai           #+#    #+#             */
/*   Updated: 2022/05/07 19:23:18 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	j;
	char	d;

	d = (char )c;
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{	
		i++;
		if (s[i] == d)
			j = i;
	}
	if (s[j] == d)
	{
		s += j;
		return ((char *)s);
	}
	return (NULL);
}
