/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/28 18:33:43 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env/env.h"
#include "../../lib/the_lib/lib.h"
#include <stdio.h>
#include <stdbool.h>

void	bi_echo(char **simple_command)
{
	int		i;
	bool	flag;

	i = 1;
	flag = true;
	while (simple_command[i] != NULL && !ft_strcmp(simple_command[i], "-n"))
	{
		flag = false;
		i++;
	}
	while (simple_command[i] != NULL)
	{
		ft_putstr_fd(simple_command[i], 1);
		if (simple_command[i + 1] != NULL)
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (flag)
		ft_putchar_fd('\n', 1);
	add_env(ft_strdup("?=0"));
}
