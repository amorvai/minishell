/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_too.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:00:03 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/16 16:45:00 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "../../lib/the_lib/lib.h"
#include <stdlib.h>

extern char	**g_envp;

char	*get_env(char *key)
{
	int	i;

	i = 0;
	while (g_envp[i] != NULL)
	{
		if (!ft_strncmp(g_envp[i], key, ft_strlen(key)))
			return (g_envp[i] + ft_strlen(key) + 1);
		i++;
	}
	return (NULL);
}

static int	copy_env_plusone(char *new_env, int env_len)
{
	char	**envp_copy;

	envp_copy = g_envp;
	g_envp = ft_calloc(env_len + 2, sizeof(char *));
	if (!g_envp)
		return (1);
	ft_memcpy(g_envp, envp_copy, env_len * sizeof(char *));
	g_envp[env_len] = new_env;
	g_envp[env_len + 1] = NULL;
	free(envp_copy);
	return (0);
}

int	add_env(char *new_env)
{
	char	**key_value;
	int		i;

	i = 0;
	key_value = ft_split(new_env, '=');
	while (g_envp[i] != NULL)
	{
		if (!ft_strncmp(g_envp[i], key_value[0], ft_strlen(key_value[0])))
		{
			free(g_envp[i]);
			g_envp[i] = new_env;
			free_splits(key_value);
			return (0);
		}
		i++;
	}
	free_splits(key_value);
	copy_env_plusone(new_env, i);
	return (0);
}

int	del_env(char *key)
{
	int	temp;
	int	i;

	i = 0;
	while (g_envp[i] != NULL)
	{
		if (!ft_strncmp(g_envp[i], key, ft_strlen(key)))
		{
			temp = i;
			free(g_envp[i]);
			g_envp[i] = NULL;
			i++;
			break ;
		}
		i++;
	}
	if (g_envp[i] == NULL)
		return (1);
	i = split_count(g_envp);
	g_envp[temp] = g_envp[i - 1];
	g_envp[i - 1] = NULL;
	return (0);
}
