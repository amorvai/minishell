/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/01/19 16:05:32 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env/env.h"
#include "../../lib/the_lib/lib.h"

void bi_echo(char **simple_command)
{
	if (ft_strcmp(simple_command[1], "-n") != 0)
	{
		ft_putstr_fd(simple_command[2], 1);
		ft_putchar_fd('\n', 1);
	}
	else
		ft_putstr_fd(simple_command[1], 1);
}