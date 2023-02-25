/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:17:42 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/25 03:02:19 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "exec.h"
#include "../signal/signals.h"
#include "../error/error.h"
#include "../env/env.h"
#include "../minishell/minishell.h"
#include "../../lib/the_lib/lib.h"
#include "../builtin/builtins.h"
#include "../parsing/parsing.h"


static void fabricating_pipes(int amo_pipes, int fds[amo_pipes][2])
{
	int i;
	
	i = 0;
	while (i < amo_pipes)
	{
		pipe(fds[i]);
		i++;
	}
}

static void	the_closer(int amo_pipes, int fds[amo_pipes][2], int i, char *flex)
{
	int	z;
	
	z = 0;
	if (ft_strcmp("parent", flex) == 0)
	{
		while (z < amo_pipes)
		{
			close(fds[z][0]);
			close(fds[z][1]);
			z++;
		}
	}
	else if (ft_strcmp("child", flex) == 0)
	{
		while (z < amo_pipes)
		{
			if (z != i - 1)
				close(fds[z][0]);
			if (z != i)
				close(fds[z][1]);
			z++;
		}
	}
}

static void	childish_behaviour(t_simp_com *c, int a_p, int fds[a_p][2], int i)
{
	if (where_ma_redirec(c) != 0)
		bi_exit(print_redirection_protection());
	the_closer(a_p, fds, i, "child");
	if (i != 0 && c->redirect_input == NULL)
		dup2(fds[i - 1][0], STDIN_FILENO);
	if (i != 0)
		close(fds[i - 1][0]);	
	if (i < a_p && c->redirect_output == NULL)
		dup2(fds[i][1], STDOUT_FILENO);
	if (i < a_p)
		close(fds[i][1]);
	decisionmaker(c->command, "child");
}

void idle_mode(int amo_cmd)
{
	int status;
	
	while (amo_cmd > 0)
	{
		wait(&status);
		//exit_status of child
		amo_cmd--;
	}
}

void multiple_pipes(t_simp_com *cmds, int amo_cmds)
{
	pid_t		pids[amo_cmds];
	int			fds[amo_cmds - 1][2];
	int			amo_pipes;
	int			i;

	i = 0;
	amo_pipes = amo_cmds - 1;
	fabricating_pipes(amo_pipes, fds);
	while(i < amo_cmds)
	{
		if ((pids[i] = fork()) < 0)
			bi_exit(print_fork_protection);
		else if (pids[i] == 0)
			childish_behaviour(cmds, amo_pipes, fds, i);
		cmds = cmds->next; 
		i++;
	}
	the_closer(amo_pipes, fds, 0, "parent");
	idle_mode(amo_cmds);
}
