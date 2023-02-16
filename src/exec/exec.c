/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:17:53 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/16 14:42:29 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../env/env.h"
#include "../builtin/builtins.h"
#include "../parsing/parsing.h" // for append_str only, will move into different file/header tho
#include "../structure/command.h"
#include "../../lib/the_lib/lib.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

extern char		**g_envp;

static void path_funct(char **simple_cmd);
static char *path_hunt(char *cmd);

void	executer(t_simp_com *head)
{
	// init_env();
	if (head == NULL)
		return ;
	where_ma_redirec(head);
	if (command_lst_len(head) > 1)
		multiple_pipes(head, command_lst_len(head) - 1);
	else
	{
		decisionmaker(head->command, "parent");
	}
	// close_ma_redirec(head);
	
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
	if (ft_strcmp(flex, "child") == 0)
		exit(EXIT_SUCCESS);
	//exit functions needs to be switched
}

static char *path_hunt(char *cmd)
{
	int		i;
	char	**paths;
	char	*path_w_slash;
	char	*path_to_ex;
	struct	stat	s;
	
	i = 0;
	paths = ft_split(get_env("PATH"), ':');
	while (paths[i] != NULL)
	{
		//
		path_w_slash = ft_strjoin(paths[i], "/");
		path_to_ex = ft_strjoin(path_w_slash, cmd);
		free(path_w_slash);
		// ^ instead of:
		// path_to_ex = ft_strjoin(paths[i], ft_strjoin("/", cmd));
		// 										^ LEAKS (str_join returns newly allocated string)
		// alternatively:
		// 		path_to_ex = ft_strjoin(paths[i], "/");
		// 		append_str(&path_to_ex, cmd, 0, ft_strlen(cmd));
		
		if (stat(path_to_ex, &s) == 0)
			break;
		i++;
		free(path_to_ex);
		path_to_ex = NULL;
	}
	free_splits(paths);
	return(path_to_ex);
}

static void path_funct(char **simple_cmd)
{
	char		*path_to_ex;
	
	path_to_ex = path_hunt(simple_cmd[0]);
	if (path_to_ex != NULL)
	{
		// sleep(1000);
		execve(path_to_ex, simple_cmd, g_envp);
		//if (just one command)
			// free_env();
			// init_env();
		//this env doesnt change our env
		//global variable need protection from data races
			// idle_mode(1);
			//this shit so weird
		free(path_to_ex);
	}
	else
	{
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(simple_cmd[0], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
}

// static char **env_to_dchar()
// {
// 	char **env;
// 	int length;
	
// 	length = 0;
// 	while (g_envp[length] != NULL)
// 		length++;
// 	env = malloc(sizeof(char *) * (length + 1));
// 	length = 0;
// 	while (g_envp[length] != NULL)
// 	{
// 		env[length] = ft_strjoin(g_envp[length]->key, g_envp[length]->value);
// 		length++;				
// 	}
// 	env[length] = NULL;
// 	return (env);
// }
