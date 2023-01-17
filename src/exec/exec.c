/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:17:53 by pnolte            #+#    #+#             */
/*   Updated: 2023/01/17 11:28:37 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_env		**g_envp;

void	executer(char **list)
{
	int i;
	
	i = 0;
	while (i)
	{
		redirection()
		check_for_pipes()
			redirection()
			fork();
				if (builtin)
					exec_builtin();
				if (!buitlin)
					search_path()
					fork();
					execv();
					wait();	
			wait()			
	}
}
