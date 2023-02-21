/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/21 19:42:05 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env/env.h"
#include "../../lib/the_lib/lib.h"
#include <stdlib.h>

void	free_and_exit(long long exit_status)
{
	exit_status = exit_status % 256;
	// everything that needs to happen before exiting
	
	// if (child)
	// add_env(ft_strjoin("?=", ft_itoa(exit_status)));
	// // else
	// 	free_env();
	exit(exit_status);
}

void	bi_exit(char **simple_com)
{
	long long	exit_status;

	if (split_count(simple_com) < 2 /* && not child */) // mir ist unklar wie ich das am besten handle
	{
		ft_atoll(get_env("?"), &exit_status);
		free_and_exit(exit_status);
	}
	// else if (split_count(simple_com) < 2 /* && child */)
	// 	free_and_exit(0);
	else if (split_count(simple_com) == 2)
	{
		if (!ft_atoll(simple_com[1], &exit_status))
			free_and_exit(exit_status);
		else
		{
			ft_putstr_fd("bash: exit: ", 2);
			ft_putstr_fd(simple_com[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
		}
	}
	else
		ft_putstr_fd("bash: exit: too many arguments\n", 2);
	add_env("?=1");
}

// datenstruktur mit allen allokierten sachen reinpassen?
