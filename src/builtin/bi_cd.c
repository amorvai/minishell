/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/20 17:04:57 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env/env.h"
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../lib/the_lib/lib.h"
#include <stdio.h>

int bi_cd(char *path)
{
	int i;
	
	add_env(ft_strjoin("OLDPWD=", (getenv("PWD"))));
	i = chdir(path);
	if (i < 0)
	{
		ft_putstr_fd("🐚: cd: Something went wrong", 2);
		return(EXIT_FAILURE);
	}
	add_env(ft_strjoin("PWD=", (getenv("PWD"))));
	printf("OLDPWD:%s\nPWD:%s\n", get_env("OLDPWD"), get_env("PWD"));
	return(EXIT_SUCCESS);
	// {
	// 	str = cd_cut(cwd);
	// 	add_env(ft_strjoin("PWD=", str));
	// }
	// else if ((s.st_mode & S_IFMT) == S_IFREG)
	// 	printf("MML: cd: %s: Not a directory:\n", path);
	// else if (path != NULL)
	// 	bi_cd2(path, cwd);
	// else
	// 	printf("MML: cd: %s: Something went not as planned\n", str);
}

// static void	bi_cd2(char *path, char *cwd)
// {
// 	char *str;
// 	char *str2;
	
// 	if (path[0] != '/')
// 	{
// 		str2 = ft_strjoin("/", path);
// 		str = ft_strjoin(cwd, str2);
// 		free(str2);
// 		if (chdir(str) == -1)
// 		{
// 			printf("MML: cd: %s: No such file or directory:\n", path);
// 			return ;
// 		}	
// 		add_env(ft_strjoin("PWD=", str));
// 		free(str);
// 	}
// 	else if (path[0] == '/')
// 	{
// 		if (chdir(path) == -1)
// 		{
// 			printf("MML: cd: %s: No such file or directory:\n", path);
// 			return ;
// 		}	
// 		add_env(ft_strjoin("PWD=", path));
// 	}
// }

// static char *check_for_cwd()
// {
// 	char *cwd;
	
// 	cwd = get_env("PWD");
// 	if (get_env("HOME") == NULL || ft_strcmp(get_env("HOME"), "") == 0)
		
// 	if (cwd == NULL || ft_strcmp(cwd, "") == 0)
// 	{
// 		if (get_env("OLDPWD") == NULL || ft_strcmp(get_env("OLDPWD"), "") == 0)
// 			add_env(ft_strdup("PWD=/"));
// 		cwd = get_env("OLDPWD");
// 	}
// 	return (cwd);
// }

// static char *cd_cut(char *path)
// {
// 	char	*shortend_path;
// 	int		i;
// 	int		j;
	
// 	i = ft_strlen(path);
// 	while (path[i] != '/')
// 		i--;
// 	shortend_path = malloc(sizeof(char) * i + 1);
// 	if (shortend_path == NULL)
// 		return (NULL);
// 	j = 0;
// 	while (j < i)
// 	{
// 		shortend_path[j] = path[j];
// 		j++;	
// 	}
// 	shortend_path[j] = '\0';
// 	return(shortend_path);
// }
