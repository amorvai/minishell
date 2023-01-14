/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/01/14 18:53:31 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../env/env.h"
#include <sys/stat.h>

static void	bi_cd2(char *path, char *cwd);
static char *check_for_cwd();
static char *cd_cut(char *path);

void bi_cd(char *path)
{
	char		*str;
	struct stat	path_stat;
	char		*cwd;
	
	str = NULL;
	cwd = check_for_cwd();
	stat(path, &path_stat);
	if (path == NULL || (path != NULL && path[0] == '~' && path[1] == '\0'))
		add_env("PWD", get_env("HOME"));
	else if (path[0] == '.' && path[1] == '.')
	{
		str = cd_cut(cwd);
		add_env("PWD", str);
	}
	else if ((path_stat.st_mode & S_IFMT) == S_IFREG)
		printf("MML: cd: %s: Not a directory:\n", path);
	else if (path != NULL)
		bi_cd2(path, cwd);
	else
		printf("MML: cd: %s: Something went not as planned\n", str);
}

static void	bi_cd2(char *path, char *cwd)
{
	char *str;
	
	if (path[0] != '/')
	{
		str = ft_strjoin(cwd, ft_strjoin("/", path));
		if (chdir(str) == -1)
		{
			printf("MML: cd: %s: No such file or directory:\n", path);
			return ;
		}	
		add_env("PWD", str);
		free(str);
	}
	else if (path[0] == '/')
	{
		if (chdir(path) == -1)
		{
			printf("MML: cd: %s: No such file or directory:\n", path);
			return ;
		}	
		add_env("PWD", path);
	}
}

static char *check_for_cwd()
{
	char *cwd;
	
	cwd = get_env("PWD");
	if (get_env("HOME") == NULL)
		add_env("HOME", "/");
	if (cwd == NULL)
	{
		if (get_env("OLDPWD") == NULL)
			add_env("PWD", "/");
		cwd = get_env("OLDPWD");
	}
	return (cwd);
}

static char *cd_cut(char *path)
{
	char	*shortend_path;
	int		i;
	int		j;
	
	i = ft_strlen(path);
	while (path[i] != '/')
		i--;
	shortend_path = malloc(sizeof(char) * i + 1);
	if (shortend_path == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		shortend_path[j] = path[j];
		j++;	
	}
	shortend_path[j] = '\0';
	return(shortend_path);
}
