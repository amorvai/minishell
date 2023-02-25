/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:17:53 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/25 16:06:17 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../env/env.h"
#include "../builtin/builtins.h"
#include "../structure/command.h"
#include "../../lib/the_lib/lib.h"
#include "../error/error.h"
#include "../signal/signals.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/stat.h>

extern char	**g_envp;

int	is_builtin(char **simple_cmd)
{
	if (ft_strcmp(simple_cmd[0], "cd") == 0)
		return (1);
	else if (ft_strcmp(simple_cmd[0], "echo") == 0)
		return (1);
	else if (ft_strcmp(simple_cmd[0], "env") == 0)
		return (1);
	else if (ft_strcmp(simple_cmd[0], "exit") == 0)
		return (1);
	else if (ft_strcmp(simple_cmd[0], "export") == 0)
		return (1);
	else if (ft_strcmp(simple_cmd[0], "pwd") == 0)
		return (1);
	else if (ft_strcmp(simple_cmd[0], "unset") == 0)
		return (1);
	return (0);
}

int	execute_builtin(t_simp_com *cmds)
{
	int	fd_zer;
	int	fd_one;

	fd_zer = dup(STDIN_FILENO);
	fd_one = dup(STDOUT_FILENO);
	if (redirector(cmds))
		return (print_redirection_protection(), 1);
	decisionmaker(cmds->command);
	dup2(fd_zer, STDIN_FILENO);
	dup2(fd_one, STDOUT_FILENO);
	close(fd_zer);
	close(fd_one);
	return (0);
}

int	create_environment_and_execute(char *executable, t_simp_com *cmds)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (print_fork_protection(), 1);
	else if (pid == 0)
	{
		if (redirector(cmds))
			return (print_redirection_protection(), 1);
		execve(executable, cmds->command, g_envp);
	}
	idle_mode(1);
	return (0);
}

static char	*path_hunt(char *cmd)
{
	char		**paths;
	char		*path_w_slash;
	char		*path_to_ex;
	struct stat	s;
	int			i;

	i = 0;
	paths = ft_split(get_env("PATH"), ':');
	if (paths == NULL || paths[0] == NULL)
		path_to_ex = cmd;
	while (paths && paths[i] != NULL)
	{
		path_w_slash = ft_xstrjoin(paths[i], "/");
		path_to_ex = ft_xstrjoin(path_w_slash, cmd);
		free(path_w_slash);
		if (stat(path_to_ex, &s) == 0)
			break ;
		free(path_to_ex);
		path_to_ex = NULL;
		i++;
	}
	free_splits(paths);
	return (path_to_ex);
}

static char	*search_and_check(char *arg_one)
{
	struct stat	s;
	char		*path;

	if (!ft_strchr(arg_one, '/'))
	{
		path = path_hunt(arg_one);
		if (path == NULL)
			return (print_command_not_found(arg_one), NULL);
	}
	else
		path = arg_one;
	if (stat(path, &s)) // if doesnt exist
	{
		if (path != arg_one)
			free(path);
		return (print_no_such(arg_one, "file_or_dire"), NULL);
	}
	if (s.st_mode != S_IXUSR) // if you have permissions
	{
		if (S_ISDIR(s.st_mode))
			return (print_is_directory(path), NULL);
	}
	else
	{
		if (path != arg_one)
			free(path);
		return (print_permission_denied(arg_one), NULL);
	}
	return (path);
}

void	execute_other(t_simp_com *cmds)
{
	char	*executable;

	executable = search_and_check(cmds->command[0]);
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
	if (command_lst_len(cmds) > 1)
		multiple_pipes(cmds, command_lst_len(cmds));
	else if (is_builtin(cmds->command))
		execute_builtin(cmds);
	else
		execute_other(cmds);
}

void	decisionmaker(char **simple_cmd)
{
	char	*executable;

	if (ft_strcmp(simple_cmd[0], "cd") == 0)
		bi_cd(simple_cmd[1]);
	else if (ft_strcmp(simple_cmd[0], "echo") == 0)
		bi_echo(simple_cmd);
	else if (ft_strcmp(simple_cmd[0], "env") == 0)
		bi_env(simple_cmd);
	else if (ft_strcmp(simple_cmd[0], "exit") == 0)
		bi_exit(simple_cmd);
	else if (ft_strcmp(simple_cmd[0], "export") == 0)
		bi_export(simple_cmd);
	else if (ft_strcmp(simple_cmd[0], "pwd") == 0)
		bi_pwd();
	else if (ft_strcmp(simple_cmd[0], "unset") == 0)
		bi_unset(simple_cmd);
	else
	{
		executable = search_and_check(simple_cmd[0]);
		if (!executable)
			bi_exit(NULL);
		execve(executable, simple_cmd, g_envp);
	}
	// if (ft_strcmp(flex, "child") == 0)
	// 	exit(EXIT_SUCCESS);
	//exit status needs to be switched to end status of child 
}
