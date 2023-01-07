/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lowerhexadec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:50:33 by amorvai           #+#    #+#             */
/*   Updated: 2022/04/28 18:57:06 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	hexlen(unsigned int x)
{
	size_t	len;

	len = 1;
	while (x != 0)
	{
		x = x / 16;
		len ++;
	}
	return (len);
}

int	print_lowerhexadec(unsigned int x)
{
	char	*table;
	char	*save;
	size_t	i;
	size_t	len;

	if (x == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	table = "0123456789abcdef";
	i = hexlen(x);
	len = i;
	save = ft_calloc(len, sizeof(char));
	if (save == NULL)
		return (-1);
	while (i > 1)
	{
		i--;
		save[i - 1] = table[x % 16];
		x = x / 16;
	}
	print_string(save);
	free(save);
	return (len - 1);
}
