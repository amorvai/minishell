/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/20 16:40:49 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env/env.h"
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../lib/the_lib/lib.h"
#include <stdio.h>

static void	bi_cd2(char *path, char *cwd);
static char *check_for_cwd();
static char *cd_cut(char *path);

void bi_cd(char *path)
{
	char		*str;
	char		*cwd;
	struct stat	s;
	
	str = NULL;
	cwd = check_for_cwd();
	stat(path, &s);
	if (path[0] == '.' && path[1] == '\0')
		return;
	else if (path == NULL || (path != NULL && path[0] == '~' && path[1] == '\0'))
		chdir("")
	
	
	// else if (path[0] == '.' && path[1] == '.' && path[2] == '\0')
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

static char *check_for_cwd()
{
	char *cwd;
	
	cwd = get_env("PWD");
	if (get_env("HOME") == NULL || ft_strcmp(get_env("HOME"), "") == 0)
		
	if (cwd == NULL || ft_strcmp(cwd, "") == 0)
	{
		if (get_env("OLDPWD") == NULL || ft_strcmp(get_env("OLDPWD"), "") == 0)
			add_env(ft_strdup("PWD=/"));
		cwd = get_env("OLDPWD");
	}
	return (cwd);
}

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
