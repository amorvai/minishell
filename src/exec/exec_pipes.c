/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:17:42 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/28 14:12:18 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../error/error.h"
#include "../env/env.h"
#include "../../lib/the_lib/lib.h"

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char	**g_envp;

static void	fabricating_pipes(int amo_pipes, int fds[amo_pipes][2])
{
	int	i;

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

static int	childish_fds(t_simp_com **c, int nb_p, int fds[nb_p][2], int i)
{
	the_closer(nb_p, fds, i, "child");
	if (i != 0 && (*c)->redirect_input == NULL)
		dup2(fds[i - 1][0], STDIN_FILENO);
	if (i != 0)
		close(fds[i - 1][0]);
	if (i < nb_p && (*c)->redirect_output == NULL)
		dup2(fds[i][1], STDOUT_FILENO);
	if (i < nb_p)
		close(fds[i][1]);
	if (redirector(c))
		return (1);
	return (0);
}

static int	execute_child(t_simp_com **c, int nb_p, int fds[nb_p][2], int i)
{
	char	*executable;
	int		exit_status;

	if (!childish_fds(c, nb_p, fds, i))
	{
		if (is_builtin((*c)->command[0]))
			execute_builtin(c);
		else
		{
			executable = get_executable_path((*c)->command[0]);
			if (executable)
				execve(executable, (*c)->command, g_envp);
		}
	}
	ft_atoi(get_env("?"), &exit_status);
	exit(exit_status);
}

void	multiple_pipes(t_simp_com **cmds, int nb_cmds)
{
	pid_t		pids[nb_cmds];
	int			fds[nb_cmds - 1][2];
	int			nb_pipes;
	int			i;
	t_simp_com	*temp;

	nb_pipes = nb_cmds - 1;
	fabricating_pipes(nb_pipes, fds);
	i = 0;
	temp = *cmds;
	while (i < nb_cmds)
	{
		pids[i] = fork();
		if (pids[i] < 0)
			print_fork_protection(); // more? exit? return? 
		else if (pids[i] == 0)
			execute_child(&temp, nb_pipes, fds, i);
		temp = temp->next;
		i++;
	}
	the_closer(nb_pipes, fds, 0, "parent");
	idle_mode(i, pids);
}
