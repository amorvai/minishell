/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:17:53 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/18 13:32:52 by amorvai          ###   ########.fr       */
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

void	executer(t_simp_com *cmds)
{
	pid_t	pid;
	
	// init_env();
	if (cmds == NULL)
		return ;
	// heredoc()
	if (command_lst_len(cmds) > 1)
		multiple_pipes(cmds, command_lst_len(cmds));
	else
	{
		if ((pid = fork()) < 0)
		{
			perror("Fork creation failed");
			exit(EXIT_FAILURE);
			//error handler
		}
		else if (pid == 0)
		{
			where_ma_redirec(cmds);
			decisionmaker(cmds->command, "parent");
		}
		idle_mode(1);
	}
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

static char *exec_hunt(char *cmd)
{
	char			**split;
	char			*path_w_slash;
	char			*path_to_ex;
	struct	stat	s;
	int				i;
	
	if (cmd[0] == '.' && cmd[1] == '/')
	{
		path_w_slash = ft_strjoin(get_env("PWD"), "/");
		path_to_ex = ft_strjoin(path_w_slash, cmd);
		free(path_w_slash);
	}
	else
	{
		split = ft_split(cmd, '/');
		i = 0;
		while (split[i] == NULL)
		{
			if (split[i][0] == '.' && split[i ][1] == '.')
			{
				path_to_ex = NULL;
			}
			i++;
		}
	}	
	if (stat(path_to_ex, &s) != 0)
	{
		free(path_to_ex);
		return (NULL);
	}
	return (path_to_ex);
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

static void path_funct(char **simple_cmd)
{
	char		*path_to_ex;
	int			i;
	
	i = 0;
	while (simple_cmd[0][i] != '\0')
	{
		if (simple_cmd[0][i] == '.' && simple_cmd[0][i + 1] == '/')
			path_to_ex = exec_hunt(simple_cmd[0]);
		i++;
	}
	if (path_to_ex != NULL)
		path_to_ex = path_hunt(simple_cmd[0]);
	if (path_to_ex != NULL)
		execve(path_to_ex, simple_cmd, g_envp);
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
