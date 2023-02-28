/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_too.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:00:03 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/28 18:44:55 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "../../lib/the_lib/lib.h"
#include <stdlib.h>
#include <stdio.h>

extern char	**g_envp;

char	*add_equal_sign(char *str)
{
	char	*new;

	new = ft_xstrjoin(str, "=");
	return (new);
}

char	*get_env(char *key)
{
	char	*keyn;
	int		i;

	keyn = add_equal_sign(key);
	i = 0;
	while (g_envp[i] != NULL)
	{
		if (!ft_strncmp(g_envp[i], keyn, ft_strlen(keyn)))
		{
			free(keyn);
			return (g_envp[i] + ft_strlen(key) + 1);
		}
		i++;
	}
	free(keyn);
	return (NULL);
}

static int	copy_env_plusone(char *new_env, int env_len)
{
	char	**envp_copy;

	envp_copy = g_envp;
	g_envp = ft_xcalloc(env_len + 2, sizeof(char *));
	ft_memcpy(g_envp, envp_copy, env_len * sizeof(char *));
	g_envp[env_len] = new_env;
	g_envp[env_len + 1] = NULL;
	free(envp_copy);
	return (0);
}

int	add_env(char *new_env)
{
	char	**key_value;
	char	*keyn;
	int		i;

	if (!new_env)
		return (1);
	i = 0;
	key_value = ft_split(new_env, '=');
	keyn = add_equal_sign(key_value[0]);
	while (g_envp[i] != NULL)
	{
		if (!ft_strncmp(g_envp[i], keyn, ft_strlen(keyn)))
		{
			free(g_envp[i]);
			g_envp[i] = new_env;
			free_splits(key_value);
			free(keyn);
			return (0);
		}
		i++;
	}
	free_splits(key_value);
	free(keyn);
	copy_env_plusone(new_env, i);
	return (0);
}

int	del_env(char *key)
{
	char	*keyn;
	int		temp;
	int		i;

	i = 0;
	temp = -1;
	keyn = add_equal_sign(key);
	while (g_envp[i] != NULL && (i == 0 || g_envp[i - 1] != NULL))
	{
		if (!ft_strncmp(g_envp[i], keyn, ft_strlen(keyn)))
		{
			temp = i;
			free(g_envp[i]);
			g_envp[i] = NULL;
		}
		i++;
	}
	if (temp == -1)
		return (free(keyn), 0);
	while (g_envp[i] != NULL)
		i++;
	g_envp[temp] = g_envp[i - 1];
	g_envp[i - 1] = NULL;
	return (free(keyn), 0);
}
