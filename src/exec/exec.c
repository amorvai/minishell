/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:17:53 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/28 14:20:31 by amorvai          ###   ########.fr       */
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
#include <sys/types.h>

extern char	**g_envp;

void idle_mode(int amo_cmd, pid_t pids[amo_cmd])
{
	int		status;
	int		exitstatus;
	char	*exitcode;
	int		i;

	i = 0;
	while (amo_cmd > i)
	{
		waitpid(pids[i], &status, 0);
		if (WIFEXITED(status))
			exitstatus = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			exitstatus = get_signals_return_value(WTERMSIG(status));
		i++;
	}
	exitcode = ft_itoa(exitstatus);
	add_env(ft_xstrjoin("?=", exitcode));
	free(exitcode);
}

static void	single_builtin(t_simp_com **c)
{
	int	fd_zer;
	int	fd_one;

	if (ft_strcmp((*c)->command[0], "exit") == 0)
		execute_builtin(c);
	fd_zer = dup(STDIN_FILENO);
	fd_one = dup(STDOUT_FILENO);
	if (redirector(c))
		print_redirection_protection();
	else
		execute_builtin(c);
	dup2(fd_zer, STDIN_FILENO);
	dup2(fd_one, STDOUT_FILENO);
	close(fd_zer);
	close(fd_one);
}

static void	create_environment_and_execute(char *executable, t_simp_com **cmds)
{
	pid_t	pid[1];
	int		exit_status;

	pid[0] = fork();
	if (pid[0] < 0)
	{
		print_fork_protection();
		return ;
	}
	else if (pid[0] == 0)
	{
		if (!redirector(cmds) && executable)
			execve(executable, (*cmds)->command, g_envp);
		ft_atoi(get_env("?"), &exit_status);
		exit(exit_status);
	}
	idle_mode(1, pid);
}

static void	execute_other(t_simp_com **cmds)
{
	char	*executable;

	executable = get_executable_path((*cmds)->command[0]);
	create_environment_and_execute(executable, cmds);
	if (executable != (*cmds)->command[0])
		free(executable);
}

void	executer(t_simp_com **cmds)
{
	if (cmds == NULL)
		return ;
	terminal_switcher("execute");
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, sig_hand);
	signal(SIGQUIT, sig_hand);
	if (command_lst_len(*cmds) > 1)
		multiple_pipes(cmds, command_lst_len(*cmds));
	else if (is_builtin((*cmds)->command[0]))
		single_builtin(cmds);
	else
		execute_other(cmds);
}
