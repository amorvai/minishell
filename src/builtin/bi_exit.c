/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/20 23:51:50 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env/env.h"
#include "../../lib/the_lib/lib.h"
#include <stdlib.h>

void	free_and_exit(long long exit_status)
{
	exit_status = exit_status % 256;
	// everything that needs to happen before exiting
	free_env();
	exit(exit_status);
}

void	bi_exit(char **simple_com)
{
	long long	exit_status;

	if (split_count(simple_com) < 2)
	{
		ft_atoll(get_env("?"), &exit_status);
		free_and_exit(exit_status);
	}
	else if (split_count(simple_com) == 2)
	{
		if (!ft_atoll(simple_com[1], &exit_status))
			free_and_exit(exit_status);
		else
			ft_putstr_fd("bash: exit: too many arguments", 2);
	}
	else
		ft_putstr_fd("bash: exit: too many arguments", 2);
	add_env("?=1");
}

// datenstruktur mit allen allokierten sachen reinpassen?
