/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:25:40 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/25 15:50:56 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "../builtin/builtins.h"
#include "../../lib/the_lib/lib.h"
#include <stdlib.h>
#include <stdio.h>

extern char	**environ;
char		**g_envp;

int	init_env(void)
{
	int		i;
	char	*cwd;

	i = split_count(environ);
	g_envp = ft_xcalloc(i + 1, sizeof(char *));
	i = 0;
	while (environ[i] != NULL)
	{
		g_envp[i] = ft_xsubstr(environ[i], 0, ft_strlen(environ[i]));
		i++;
	}
	g_envp[i] = NULL;
	if (!get_env("PWD"))
	{
		cwd = grab_cwd();
		if (cwd)
		{
			add_env(ft_xstrjoin("PWD=", cwd));
			free(cwd);
		}
	}
	add_env(ft_xstrdup("?=0"));
	add_env(ft_xstrdup("42heredoc=no"));
	return (0);
}

void	print_env(void)
{
	int	i;

	i = 0;
	if (!g_envp)
	{
		printf("(there is nothing here)\n");
		return ;
	}
	while (g_envp && g_envp[i] != NULL)
	{
		if (ft_strncmp("42heredoc", g_envp[i], 9) == 0 
			|| ft_strncmp("?", g_envp[i], 1) == 0)
			;
		else
			printf("%s\n", g_envp[i]);
		i++;
	}
}

void	free_env(void)
{
	free_splits(g_envp);
}
