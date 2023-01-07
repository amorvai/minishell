/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:24:34 by amorvai           #+#    #+#             */
/*   Updated: 2022/04/02 16:45:00 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*real_itoa(char *str, int n, int i)
{
	while (n > 0 || n < 0)
	{
		if (n < 0)
			str[i] = (-(n % 10)) + 48;
		else
			str[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	if (i == 0)
		str[i] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		a;
	int		i;
	char	*str;

	a = n;
	i = 0;
	while (a > 9 || a < -9)
	{
		a = a / 10;
		i++;
	}
	if (n < 0)
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	return (real_itoa(str, n, i));
}
