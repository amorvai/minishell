/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/01/13 14:24:35 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../env/env.h"

void bi_echo(char *string, int flag)
{
	int i;

	i = 0;
	if (flag == 0)
	{
		ft_putstr_fd(string, 1);
		ft_putchar_fd('\n', 1);
	}
	else
		ft_putstr_fd(string, 1);
}