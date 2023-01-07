/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:43:10 by amorvai           #+#    #+#             */
/*   Updated: 2022/04/28 18:57:10 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	intlen(int i)
{
	int	j;

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

int	print_int(int i)
{
	ft_putnbr_fd(i, 1);
	return (intlen(i));
}
