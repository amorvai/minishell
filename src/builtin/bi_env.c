/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/25 10:38:13 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env/env.h"
#include "../../lib/the_lib/lib.h"
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void bi_env(char **simple_command)
{
	if (ft_strcmp(simple_command[1], "pwd") == 0 || ft_strcmp(simple_command[1], "PWD") == 0)
	{
		ft_putstr_fd(get_env("PWD"), 1);
		ft_putstr_fd("\n", 1);
		add_env(ft_strdup("?=0"));
		return ;
	}
	else if (simple_command[1] != NULL)
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(simple_command[1], 2);
		ft_putstr_fd(": No such file or directory", 2);
		add_env(ft_strdup("?=1"));
		return ;
	}
	else
		print_env();
	add_env(ft_strdup("?=0"));
}
