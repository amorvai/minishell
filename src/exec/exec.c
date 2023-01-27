/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:17:53 by pnolte            #+#    #+#             */
/*   Updated: 2023/01/27 17:29:20 by pnolte           ###   ########.fr       */
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

static void decisionmaker(char **simple_cmd);
static void path_funct(char **simple_cmd);
static char **env_to_dc();
static int	command_and_counter(t_simp_com *head);

static int command_and_counter(t_simp_com *head)
{
	int i;
	
	i = 0;
	while (head != NULL)
	{
		i++;
		head = head->next;
	}
	return (i);
}

static void piping_mother(t_simp_com *head, int simp_l)
{
	t_simp_com *copy;
	pid_t pid[simp_l];
	int fds[2];
	int i;
	
	i = 0;
	pipe(fds);
	pid[i] = fork();
	if (pid == 0)
	{
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
		close(fds[1]);
		head = head->next;
		decisionmaker(head->command);
	}
	close(fds[0]);
	// printf("parent\n");
	dup2(fds[1], STDOUT_FILENO);
	decisionmaker(head->command);
	close(fds[1]);
	waitpid(pid, &simp_l, 0);
}

static void where_ma_pipes(t_simp_com *head)
{
	int i;
	
	i = command_and_counter(head);
	if (i > 1)
		piping_mother(head, i);
	else
		decisionmaker(head->command);
}

void	executer(t_simp_com *head)
{
	
	init_env();
	where_ma_pipes(head);
	
	
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

static void	decisionmaker(char **simple_cmd)
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
		// printf("%s\n", tmp);
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


