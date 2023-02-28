/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/28 14:27:13 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env/env.h"
#include "../structure/command.h"
#include "../../lib/the_lib/lib.h"

#include <stdlib.h>
#include <stdio.h>
#include <readline/history.h>

void	free_and_exit(long long exit_status, t_simp_com **c)
{
	char	*exit_nb;

	exit_status = exit_status % 256;
	// everything that needs to happen before exiting
	
	exit_nb = ft_itoa(exit_status);
	add_env(ft_xstrjoin("?=", exit_nb));
	free(exit_nb);
	free_env();
	command_lst_clear(c);
	clear_history();
	exit(exit_status);
}

int	check_numeric_arg(char *str, long long *exit_status)
{
	if (ft_atoll(str, exit_status))
	{
		ft_putstr_fd("bash: exit: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		*exit_status = 255;
		return (1);
	}
	return (0);
}

void	bi_exit(t_simp_com **c)
{
	long long	exit_status;
	char		*exit_nb;

	exit_status = 1;
	if (split_count((*c)->command) < 2) // mir ist unklar wie ich das am besten handle
	{
		ft_atoll(get_env("?"), &exit_status);
		free_and_exit(exit_status, c);
	}
	else if (split_count((*c)->command) == 2)
	{
		check_numeric_arg((*c)->command[1], &exit_status);
		free_and_exit(exit_status, c);
	}
	else if (!check_numeric_arg((*c)->command[1], &exit_status))
	{
		exit_status = 1;
		ft_putstr_fd("bash: exit: too many arguments\n", 2);
	}
	exit_nb = ft_itoa(exit_status);
	add_env(ft_xstrjoin("?=", exit_nb));
	free(exit_nb);
}

// datenstruktur mit allen allokierten sachen reinpassen?
