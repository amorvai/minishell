/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigneddecimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:45:00 by amorvai           #+#    #+#             */
/*   Updated: 2022/04/28 18:56:57 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	unsigned_intlen(unsigned int i)
{
	int		j;

	j = 0;
	if (i <= 0)
		j++;
	while (i != 0)
	{
		i = i / 10;
		j++;
	}
	return (j);
}

int	print_unsigneddecimal(unsigned int u)
{
	char	a;

	if (u > 9)
	{
		print_unsigneddecimal(u / 10);
		print_unsigneddecimal(u % 10);
	}
	else
	{
		a = u + 48;
		write(1, &a, 1);
	}
	return (unsigned_intlen(u));
}
