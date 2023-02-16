/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_too.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:00:03 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/16 12:44:23 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "../minishell/minishell.h"
#include "../../lib/the_lib/lib.h"
#include <stdlib.h>

extern t_env		**g_envp;

char	*get_env(char *key)
{
	int	i;

	i = 0;
	while (g_envp[i] != NULL)
	{
		if (!ft_strcmp(g_envp[i]->key, key))
			return (g_envp[i]->value);
		i++;
	}
	return (NULL);
}

static int	copy_env_plusone(char *key, char *value, int env_len)
{
	t_env	**envp_copy;

	envp_copy = g_envp;
	g_envp = NULL;
	g_envp = ft_calloc(env_len + 2, sizeof(t_env *));
	if (!g_envp)
		return (1);
	ft_memcpy(g_envp, envp_copy, env_len * sizeof(t_env));
	g_envp[env_len + 1] = NULL;
	g_envp[env_len] = ft_calloc(1, sizeof(t_env));
	g_envp[env_len]->key = ft_strdup(key);
	g_envp[env_len]->value = ft_strdup(value);
	free(envp_copy);
	return (0);
}

int	add_env(char *key, char *value)
{
	int	i;

	i = 0;
	while (g_envp[i] != NULL)
	{
		//if (!ft_strcmp(g_envp[i]->key, key))
		if (ft_strcmp(g_envp[i]->key, key) == 0)
		{
			if (value != NULL && g_envp[i]->value != NULL)
			{	
				free(g_envp[i]->value);
				g_envp[i]->value = ft_strdup(value);
			}
			return (0);
		}
		i++;
	}
	copy_env_plusone(key, value, i);
	return (0);
}

int	del_env(char *key)
{
	int	temp;
	int	i;

	i = 0;
	while (g_envp[i] != NULL)
	{
		if (!ft_strcmp(g_envp[i]->key, key))
		{
			temp = i;
			free(g_envp[i]->key);
			free(g_envp[i]->value);
			free(g_envp[i]);
			g_envp[i] = NULL;
			i++;
			break ;
		}
		i++;
	}
	if (g_envp[i] == NULL)
		return (1);
	while (g_envp[i] != NULL)
		i++;
	g_envp[temp] = g_envp[i - 1];
	g_envp[i - 1] = NULL;
	return (0);
}
