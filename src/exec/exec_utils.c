/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:09:39 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/28 17:42:36 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env/env.h"
#include "../structure/command.h"
#include "../builtin/builtins.h"
#include "../error/error.h"
#include "../../lib/the_lib/lib.h"

#include <stdlib.h> // free
#include <sys/stat.h>
#include <stdio.h>

int	check_validity(char *filename, char *path)
{
	struct stat	s;

	if (!path)
		path = filename;
	if (stat(path, &s))
	{
		return (print_no_such(filename, "file_or_dire", 'c'), 1);
	}
	if (s.st_mode & S_IXUSR)
	{
		if (S_ISDIR(s.st_mode))
			return (print_is_directory(filename), 1);
	}
	else
		return (print_permission_denied(filename, 'c'), 1);
	return (0);
}

static void	path_hunt(char *cmd, char **path_to_ex)
{
	char		**paths;
	char		*path_w_slash;
	struct stat	s;
	int			i;

	paths = NULL;
	if (!ft_strchr(cmd, '/'))
		paths = ft_split(get_env("PATH"), ':');
	if (paths == NULL || paths[0] == NULL)
		*path_to_ex = cmd;
	i = 0;
	while (paths && paths[i] != NULL)
	{
		path_w_slash = ft_xstrjoin(paths[i], "/");
		*path_to_ex = ft_xstrjoin(path_w_slash, cmd);
		free(path_w_slash);
		if (stat(*path_to_ex, &s) == 0)
			break ;
		free(*path_to_ex);
		*path_to_ex = NULL;
		i++;
	}
	if (*path_to_ex == NULL)
		print_command_not_found(cmd);
	free_splits(paths);
}

char	*get_executable_path(char *arg_one)
{
	char	*executable;

	if (arg_one == NULL)
		return (NULL);
	if (arg_one[0] == '\0' || (ft_strcmp(arg_one, ".") == 0
			|| ft_strcmp(arg_one, "..") == 0))
	{
		print_command_not_found(arg_one);
		return (NULL);
	}
	executable = NULL;
	path_hunt(arg_one, &executable);
	if (!executable || check_validity(arg_one, executable))
	{
		if (executable && executable != arg_one)
			free(executable);
		return (NULL);
	}
	return (executable);
}

void	execute_builtin(t_simp_com **c)
{
	if (ft_strcmp((*c)->command[0], "cd") == 0)
		bi_cd((*c)->command[1]);
	else if (ft_strcmp((*c)->command[0], "echo") == 0)
		bi_echo((*c)->command);
	else if (ft_strcmp((*c)->command[0], "env") == 0)
		bi_env((*c)->command);
	else if (ft_strcmp((*c)->command[0], "exit") == 0)
		bi_exit(c);
	else if (ft_strcmp((*c)->command[0], "export") == 0)
		bi_export((*c)->command);
	else if (ft_strcmp((*c)->command[0], "pwd") == 0)
		bi_pwd();
	else if (ft_strcmp((*c)->command[0], "unset") == 0)
		bi_unset((*c)->command);
}

int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	else if (ft_strcmp(cmd, "env") == 0)
		return (1);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	else if (ft_strcmp(cmd, "export") == 0)
		return (1);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	return (0);
}
