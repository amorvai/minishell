/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:54:14 by amorvai           #+#    #+#             */
/*   Updated: 2022/06/07 19:06:45 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	handle_conversion(char c, va_list list)
{
	if (c == 'c')
		return (print_char(va_arg(list, int)));
	if (c == 's')
		return (print_string(va_arg(list, char *)));
	if (c == 'p')
		return (print_voidptr(va_arg(list, unsigned long)));
	if (c == 'i' || c == 'd')
		return (print_int(va_arg(list, int)));
	if (c == 'u')
		return (print_unsigneddecimal(va_arg(list, unsigned int)));
	if (c == 'x')
		return (print_lowerhexadec(va_arg(list, unsigned int)));
	if (c == 'X')
		return (print_upperhexadec(va_arg(list, unsigned int)));
	if (c == '%')
		ft_putchar_fd(c, 1);
	return (1);
}

static int	ft_printf_b(const char *s, size_t i, va_list list, int size_print)
{
	int	ret;

	while (s != NULL && s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (ft_strchr("cspdiuxX%%", s[i]))
			{
				ret = handle_conversion(s[i], list);
				if (ret == -1)
					va_end(list);
				if (ret == -1)
					return (-1);
				size_print = size_print + ret - 2;
				i++;
			}
			else
				size_print--;
			continue ;
		}
		ft_putchar_fd(s[i++], 1);
	}
	va_end(list);
	return (size_print + i);
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	va_list	list;
	int		size_print;

	i = 0;
	size_print = 0;
	va_start(list, s);
	return (ft_printf_b(s, i, list, size_print));
}
