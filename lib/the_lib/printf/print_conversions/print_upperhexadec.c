/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_upperhexadec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:51:59 by amorvai           #+#    #+#             */
/*   Updated: 2022/04/28 18:56:51 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_upperhexadec(unsigned int X)
{
	char	*table;
	char	*save;
	size_t	i;
	size_t	len;

	if (X == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	table = "0123456789ABCDEF";
	i = hexlen(X);
	len = i;
	save = ft_calloc(len, sizeof(char));
	if (save == NULL)
		return (-1);
	while (i > 1)
	{
		i--;
		save[i - 1] = table[X % 16];
		X = X / 16;
	}
	print_string(save);
	free(save);
	return (len - 1);
}
