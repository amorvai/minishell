/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:17:53 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/14 17:12:00 by pnolte           ###   ########.fr       */
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

static void path_funct(char **simple_cmd);
static char *path_hunt(char *cmd);
static char **env_to_dchar();

void	executer(t_simp_com *head)
{
	init_env();
	if (head == NULL)
		return ;
	where_ma_redirec(head);
	if (command_and_counter(head) > 0)
		multiple_pipes(head, command_and_counter(head) - 1);
	else
		decisionmaker(head->command,  "parent");
	
	
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
	// perror("hello");
	if (ft_strcmp(flex, "child") == 0)
		exit(EXIT_SUCCESS);
	//exit functions needs to be switched
}

static char *path_hunt(char *cmd)
{
	int		i;
	char	**paths;
	char	*path_to_ex;
	struct	stat	s;
	
	i = 0;
	paths = ft_split(get_env("PATH"), ':');
	while (paths[i] != NULL)
	{
		path_to_ex = ft_strjoin(paths[i], ft_strjoin("/", cmd));
		if (stat(path_to_ex, &s) == 0)
			break;
		i++;
		path_to_ex = NULL;
		free(path_to_ex);
	}
	return(path_to_ex);
}

static void path_funct(char **simple_cmd)
{
	char		**env;
	char		*path_to_ex;
	
	path_to_ex = path_hunt(simple_cmd[0]);
	if (path_to_ex != NULL)
	{
		env = env_to_dchar();
		// sleep(1000);
		execve(path_to_ex, simple_cmd, env);
			// idle_mode(1);
			//this shit so weird
	}
	else
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(simple_cmd[0], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	free(path_to_ex);
}

static char **env_to_dchar()
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


