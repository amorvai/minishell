/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_voidptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:30:50 by amorvai           #+#    #+#             */
/*   Updated: 2022/04/28 19:02:45 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	adresslen(unsigned long p)
{
	size_t	len;

	len = 1;
	while (p != 0)
	{
		p = p / 16;
		len ++;
	}
	return (len);
}

int	print_voidptr(unsigned long p)
{
	char	*table;
	char	*save;
	size_t	i;
	size_t	len;

	if (p == 0)
		write(1, "0x0", 3);
	if (p == 0)
		return (3);
	table = "0123456789abcdef";
	i = adresslen(p);
	len = i;
	save = ft_calloc(len, sizeof(char));
	if (save == NULL)
		return (-1);
	write(1, "0x", 2);
	while (i > 1)
	{
		i--;
		save[i - 1] = table[p % 16];
		p = p / 16;
	}
	print_string(save);
	free(save);
	return (len + 1);
}
