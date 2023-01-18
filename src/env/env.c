/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:25:40 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/18 19:32:26 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "../../inc/minishell.h"
#include "../../lib/the_lib/lib.h"
#include <stdlib.h>

extern char	**environ;
t_env		**g_envp;

static void	get_len(char *environ_line, int *key, int *value)
{
	*key = 0;
	*value = 0;
	while (environ_line[*key] != '\0' && environ_line[*key] != '=')
		(*key)++;
	if (environ_line[*key] == '\0')
	{
		*key = 0;
		return ;
	}
	while (environ_line[*key + 1 + *value] != '\0')
		(*value)++;
}

static t_env	*get_env_line(char *environ_line)
{
	t_env	*env;
	int		key_len;
	int		value_len;

	env = ft_calloc(1, sizeof(t_env));
	get_len(environ_line, &key_len, &value_len);
	env->key = ft_substr(environ_line, 0, key_len);
	if (!env->key)
		return (NULL);
	env->value = ft_substr(environ_line, key_len + 1, value_len);
	if (!env->value)
		return (free(env->key), NULL);
	return (env);
}

int	init_env(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (environ[j] != NULL)
		j++;
	g_envp = ft_calloc(j + 1, sizeof(t_env *));
	while (i < j)
	{
		// printf("line: %i\n", i);
		g_envp[i] = get_env_line(environ[i]);
		if (g_envp[i] == NULL)
			return (1);
		i++;
	}
	g_envp[i] = NULL;
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
		printf("%s=%s\n", g_envp[i]->key, g_envp[i]->value);
		i++;
	}
}

void	free_env(void)
{
	int	i;

	i = 0;
	if (g_envp)
	{
		while (g_envp[i] != NULL)
		{
			free(g_envp[i]->key);
			free(g_envp[i]->value);
			free(g_envp[i]);
			i++;
		}
		free(g_envp);
		g_envp = NULL;
	}
}
