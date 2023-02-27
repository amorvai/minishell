/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/27 19:20:37 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env/env.h"
#include "../error/error.h"
#include "../../lib/the_lib/lib.h"
#include "../builtin/builtins.h"

#include <unistd.h>
#include <stdbool.h>

void bi_unset(char **cmds)
{
	int		i;
	
	i = 1;
	while (cmds[i] != NULL)
	{
		if (ft_strcmp("", cmds[i]) == 0 || cmds[i][0] == '?' 
			|| cmds[i][0] == '$' || cmds[i][0] == '=' ||
			variable_name_allowed(cmds[i], cmds[i]) == true)
			print_export_unset(cmds[i], "unset");
		else
			del_env(cmds[i]);
		i++;
	}
	
}
