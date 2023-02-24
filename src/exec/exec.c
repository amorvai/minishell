/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:17:53 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/24 16:46:42 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../env/env.h"
#include "../builtin/builtins.h"
#include "../parsing/parsing.h" // for append_str only, will move into different file/header tho
#include "../structure/command.h"
#include "../../lib/the_lib/lib.h"
#include "../error/error.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

extern char		**g_envp;

static int path_funct(char **simple_cmd);
static char *path_hunt(char *cmd, struct stat s);
int	is_builtin(char **simple_cmd);

int	executer(t_simp_com *cmds)
{
	pid_t	pid;
	int		fd_0;
	int		fd_1;
	
	if (cmds == NULL)
		return (0);
	// heredoc()
	if (command_lst_len(cmds) > 1)
		multiple_pipes(cmds, command_lst_len(cmds));
	else if (is_builtin(cmds->command))
	{
		fd_1 = dup(STDOUT_FILENO);
		fd_0 = dup(STDIN_FILENO);
		if (where_ma_redirec(cmds) != 0)
				return(print_redirection_protection());
		decisionmaker(cmds->command, "parent");
		dup2(fd_0, STDIN_FILENO);
		dup2(fd_1, STDOUT_FILENO);
		close(fd_0);
		close(fd_1);
	}
	else
	{
		if ((pid = fork()) < 0)
			return(print_fork_protection());
		else if (pid == 0)
		{
			if (where_ma_redirec(cmds) != 0)
				bi_exit(print_redirection_protection());
			decisionmaker(cmds->command, "child");
		}
		idle_mode(1);
	}
	return(EXIT_SUCCESS);
}

void	decisionmaker(char **simple_cmd, char *flex)
{
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
		path_funct(simple_cmd);
	if (ft_strcmp(flex, "child") == 0)
		exit(EXIT_SUCCESS);
	//exit status needs to be switched to end status of child 
}

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
	else
		return (0);
}

static char *path_hunt(char *cmd, struct stat s)
{
	int		i;
	char	**paths;
	char	*path_w_slash;
	char	*path_to_ex;
	
	i = 0;
	paths = ft_split(get_env("PATH"), ':');
	while (paths[i] != NULL)
	{
		path_w_slash = ft_strjoin(paths[i], "/");
		path_to_ex = ft_strjoin(path_w_slash, cmd);
		free(path_w_slash);
		if (stat(path_to_ex, &s) == 0)
			break;
		i++;
		free(path_to_ex);
		path_to_ex = NULL;
	}
	free_splits(paths);
	return(path_to_ex);
}

static int path_funct(char **simple_cmd)
{
	char		*path_to_ex;
	struct stat	s;
	
	if (stat(simple_cmd[0], &s) == 0 && S_ISREG(s.st_mode))
	{
		if (s.st_mode != S_IXUSR)
			execve(simple_cmd[0], simple_cmd, g_envp);
		else
			return (print_permission_denied(simple_cmd[0]));
	}
	else
	{
		path_to_ex = path_hunt(simple_cmd[0], s);
		if (path_to_ex != NULL)
			execve(path_to_ex, simple_cmd, g_envp);
		else
			return (print_command_not_found(simple_cmd[0]));
	}
	return (EXIT_SUCCESS);
}
