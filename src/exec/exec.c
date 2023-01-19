/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:17:53 by pnolte            #+#    #+#             */
/*   Updated: 2023/01/19 16:07:49 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../minishell/minishell.h"
#include "../env/env.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include "../../lib/the_lib/lib.h"
#include "../builtin/builtins.h"

t_env		**g_envp;

static void	is_builtin(char **simple_cmd)
{
	if (ft_strcmp(simple_cmd[0], "cd") == 0)
		bi_cd(simple_cmd[1]);
	if (ft_strcmp(simple_cmd[0], "echo") == 0)
		bi_echo(simple_cmd);
	// if (ft_strcmp(simple_cmd[0], "env") == 0)
	// 	bi_env(simple_cmd);
	if (ft_strcmp(simple_cmd[0], "exit") == 0)
		bi_exit(simple_cmd);
	if (ft_strcmp(simple_cmd[0], "export") == 0)
		bi_export(simple_cmd);
	if (ft_strcmp(simple_cmd[0], "pwd") == 0)
		bi_pwd();
	if (ft_strcmp(simple_cmd[0], "unset") == 0)
		bi_unset(simple_cmd);
}

static char **env_to_dc()
{
	char **env;
	int length;
	
	length = 0;
	while (g_envp[length] != NULL)
		length++;
	env = malloc(sizeof(char) * length + 1);
	length = 0;
	while (g_envp[length] != NULL)
	{
		env[length] = ft_strjoin(g_envp[length]->key, g_envp[length]->value);
		length++;				
	}
	env[length] = NULL;
	return (env);
}

static void path_funct(char **simple_cmd)
{
	char **paths;
	char **env;
	char *tmp;
	struct stat *s;
	int i;
	
	s = NULL;
	paths = ft_split(get_env("PATH"), ':');
	i = 0;
	while (paths[i] != NULL)
	{
		tmp = ft_strjoin(paths[i], ft_strjoin("/", simple_cmd[0]));
		if (stat(tmp, s) == 0)
		{
			i = 0;	
			break;
		}
		i++;
		free(tmp);
	}
	if (i == 0)
	{
		env = env_to_dc();
		execve(tmp, simple_cmd, env);
	}
	else	
		printf("bash: %s: command not found", simple_cmd[0]);
	free(tmp);
}

void	executer(t_simple_command **head)
{
	t_simple_command *copy;
	
	(void)copy;
	is_builtin(head[0]->arguments);
	path_funct(head[0]->arguments);
	
	// redirection()
	// check_for_pipes()
	// redirection()
	// fork();
		// 		exec_builtin();
		// 	if (!buitlin)
		// 		search_path()
		// 		fork();
		// 		execv();
		// 		wait();	
		// wait()	
}
