/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:17:53 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/27 21:21:56 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../env/env.h"
#include "../error/error.h"
#include "../signal/signals.h"
#include "../builtin/builtins.h"
#include "../structure/command.h"
#include "../../lib/the_lib/lib.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>

extern char	**g_envp;

void idle_mode(int amo_cmd)
{
	int		status;
	int		exitstatus;
	char	*exitcode;
	
	while (amo_cmd > 0)
	{
		wait(&status);
		if (WIFEXITED(status))
			exitstatus = WEXITSTATUS(status);
		else
			exitstatus = 1;
		amo_cmd--;
	}
	exitcode = ft_itoa(exitstatus);
	add_env(ft_xstrjoin("?=", exitcode));
	free(exitcode);
}

static void	single_builtin(t_simp_com *c)
{
	int	fd_zer;
	int	fd_one;

	fd_zer = dup(STDIN_FILENO);
	fd_one = dup(STDOUT_FILENO);
	if (redirector(c))
		print_redirection_protection();
	else
		execute_builtin(c->command);
	dup2(fd_zer, STDIN_FILENO);
	dup2(fd_one, STDOUT_FILENO);
	close(fd_zer);
	close(fd_one);
}

static void	create_environment_and_execute(char *executable, t_simp_com *cmds)
{
	pid_t	pid;
	int		exit_status;

	pid = fork();
	if (pid < 0)
	{
		print_fork_protection();
		return ;
	}
	else if (pid == 0)
	{
		if (redirector(cmds))
		{
			ft_atoi(get_env("?"), &exit_status);
			exit(exit_status);
		}
		execve(executable, cmds->command, g_envp);
	}
	idle_mode(1);
}

static void	execute_other(t_simp_com *cmds)
{
	char	*executable;

	executable = get_executable_path(cmds->command[0]);
	if (!executable)
		return ;
	create_environment_and_execute(executable, cmds);
	if (executable != cmds->command[0])
		free(executable);
}

void	executer(t_simp_com *cmds)
{
	if (cmds == NULL)
		return ;
	terminal_switcher("execute");
	if (command_lst_len(cmds) > 1)
		multiple_pipes(cmds, command_lst_len(cmds));
	else if (is_builtin(cmds->command[0]))
		single_builtin(cmds);
	else
		execute_other(cmds);
}
