/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/28 19:19:50 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env/env.h"
#include "../../lib/the_lib/lib.h"

#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>
#include <stdio.h>

static int	switch_heel(char *path)
{
	char		oldpwd[PATH_MAX];
	char		cwd[PATH_MAX];

	if (getcwd(oldpwd, sizeof(oldpwd)) != NULL)
		add_env(ft_xstrjoin("OLDPWD=", oldpwd));
	else
		ft_putstr_fd("miesmuschel: cd: getcwd OLDPWD error\n", 2);
	if (chdir(path) < 0)
	{
		ft_putstr_fd("miesmuschel: cd: chdir error\n", 2);
		return (EXIT_FAILURE);
	}
	else
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			add_env(ft_strjoin("PWD=", cwd));
		else
		{
			ft_putstr_fd("miesmuschel: cd: getcwd PWD error\n", 2);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

void	bi_cd(char *path)
{
	struct stat	s;
	int			r_v[2];

	if (path == NULL || (path[0] == '~' && path[1] == '\0'))
		r_v[1] = switch_heel(get_env("HOME"));
	else if (path[0] == '-' && path[1] == '\0')
		r_v[1] = switch_heel(get_env("OLDPWD"));
	else if ((r_v[0] = stat(path, &s)) >= 0 && S_ISDIR(s.st_mode))
		r_v[1] = switch_heel(path);
	else
	{
		ft_putstr_fd("🐚: cd: ", 2);
		ft_putstr_fd(path, 2);
		if (r_v[0] == -1)
			ft_putstr_fd(": No such file or directory\n", 2);
		else
			ft_putstr_fd(": Not a directory\n", 2);
		add_env(ft_xstrdup("?=1"));
		return ;
	}	
	if (r_v[1] == EXIT_FAILURE)
		add_env(ft_xstrdup("?=1"));
	else
		add_env(ft_xstrdup("?=0"));
	return ;
}
