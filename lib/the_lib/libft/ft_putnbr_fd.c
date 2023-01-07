/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:28:07 by amorvai           #+#    #+#             */
/*   Updated: 2022/04/02 18:44:56 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	if (n < 0)
	{
		a = '-';
		write(fd, &a, 1);
		if (n != -2147483648)
			ft_putnbr_fd(-n, fd);
		else
			write(fd, "2147483648", 10);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		a = n + 48;
		write(fd, &a, 1);
	}
}
