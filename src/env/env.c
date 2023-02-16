/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:25:40 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/16 16:22:35 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "../../lib/the_lib/lib.h"
#include <stdlib.h>
#include <stdio.h>

extern char	**environ;
char		**g_envp;

int	init_env()
{
	int	i;

	i = split_count(environ);
	g_envp = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (environ[i] != NULL)
	{
		g_envp[i] = ft_substr(environ[i], 0, ft_strlen(environ[i]));
		if (g_envp[i] == NULL)
			return (1); // solve alternatively / calloc or die
		i++;
	}
	g_envp[i] = NULL;
	return (0);
}

void	print_env()
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
		printf("%s\n", g_envp[i]);
		i++;
	}
}

void	free_env(void)
{
	free_splits(g_envp);
}
