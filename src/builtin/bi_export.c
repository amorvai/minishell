/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/01/19 16:05:17 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env/env.h"
#include "unistd.h"
#include "stdlib.h"

int bi_export(char **simple_command)
{
	if (simple_command[1] == NULL)
		add_env(simple_command[0], "");
	add_env(simple_command[0], simple_command[1]);
	return (EXIT_SUCCESS);
}