/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/27 21:50:35 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env/env.h"
#include "../../lib/the_lib/lib.h"
#include <stdio.h>

static void bi_echo2(char **simple_command);

void bi_echo(char **simple_command)
{
	int i;
	
	if (ft_strcmp(simple_command[1], "-n") != 0)
	{
		i = 1;
		while (simple_command[i] != NULL)
		{
			ft_putstr_fd(simple_command[i], 1);
			if (simple_command[i + 1] != NULL)
				ft_putchar_fd(' ', 1);
			i++;
		}
		ft_putchar_fd('\n', 1);	
	}
	else
		bi_echo2(simple_command);
	add_env(ft_strdup("?=0"));
}

static void bi_echo2(char **simple_command)
{
	int i;
	
	i = 2;
	while (simple_command[i] != NULL)
	{
		if (ft_strcmp(simple_command[i], "-n") != 0)
		{
			ft_putstr_fd(simple_command[i], 1);
			if (simple_command[i + 1] != NULL)
				ft_putchar_fd(' ', 1);
		}
		i++;
	}
}
