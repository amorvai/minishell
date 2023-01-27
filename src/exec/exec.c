/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:17:53 by pnolte            #+#    #+#             */
/*   Updated: 2023/01/27 14:51:00 by pnolte           ###   ########.fr       */
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
#include "../parsing/parsing.h"

t_env		**g_envp;
static void decider_bi_patch(char **simple_cmd);
static void path_funct(char **simple_cmd);
static char **env_to_dc();

void	executer(t_simp_com *head)
{
	t_simp_com *copy;
	
	(void)copy;
	init_env();
	decider_bi_path(head->command);
	
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

static void	decider_bi_path(char **simple_cmd)
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
}

static void path_funct(char **simple_cmd)
{
	char **paths;
	char **env;
	char *tmp;
	struct stat s;
	int i;
	
	paths = ft_split(get_env("PATH"), ':');
	i = 0;
	while (paths[i] != NULL)
	{
		tmp = ft_strjoin(paths[i], ft_strjoin("/", simple_cmd[0]));
		printf("%s\n", tmp);
		if (stat(tmp, &s) == 0)
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
		printf("bash: %s: command not found\n", simple_cmd[0]);
	// free(tmp);
}

static char **env_to_dc()
{
	char **env;
	int length;
	
	length = 0;
	while (g_envp[length] != NULL)
		length++;
	env = malloc(sizeof(char *) * (length + 1));
	length = 0;
	while (g_envp[length] != NULL)
	{
		env[length] = ft_strjoin(g_envp[length]->key, g_envp[length]->value);
		length++;				
	}
	env[length] = NULL;
	return (env);
}


