/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anna <anna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:10:25 by amorvai           #+#    #+#             */
/*   Updated: 2022/12/08 11:31:08 by anna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		print_char(char c);
int		print_string(char *s);
int		print_voidptr(unsigned long p);
int		print_int(int i);
int		print_unsigneddecimal(unsigned int u);
int		print_lowerhexadec(unsigned int x);
int		print_upperhexadec(unsigned int X);
size_t	hexlen(unsigned int x);

#endif 