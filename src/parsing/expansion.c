/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:47:14 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/24 17:45:46 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h" // append_str
#include "../env/env.h" // get_env
#include "../../lib/the_lib/lib.h"
#include <stdio.h> // for NULL

static char	*get_key_name(const char *str, int i)
{
	int	j;

	j = 0;
	while (str[i + j] != '\0' && !ft_strchr("\'\"$ \t\n", str[i + j]))
		j++;
	if (j > 0)
		return (ft_xsubstr(str, i, j));
	return (NULL);
}

char	*expand_env_var(char *command_str, const char *str, size_t *i)
{
	char	*env_key;
	char	*env_value;

	env_key = get_key_name(str, *i);
	if (!env_key)
	{
		command_str = append_str(command_str, "$", 0, 1);
		return (command_str);
	}
	env_value = get_env(env_key);
	if (env_value)
		command_str = append_str(command_str,
				env_value, 0, ft_strlen(env_value));
	*i = *i + ft_strlen(env_key);
	free(env_key);
	return (command_str);
}

char	*expand_sing_quote(char *command_str, const char *str, size_t *i)
{
	size_t	j;

	j = 0;
	while (str[*i + j] != '\'')
		j++;
	command_str = append_str(command_str, str, *i, j);
	*i = *i + j + 1;
	return (command_str);
}

static char	*expand_doub_quote(char *command_str, const char *str, size_t *i)
{
	char	*quoted;
	size_t	j;

	quoted = NULL;
	j = 0;
	while (str[*i + j] != '\"')
	{
		if (str[*i + j] == '$')
		{
			quoted = append_str(quoted, str, *i, j);
			*i = *i + j + 1;
			j = 0;
			quoted = expand_env_var(quoted, str, i);
		}
		else
			j++;
	}
	quoted = append_str(quoted, str, *i, j);
	*i = *i + j + 1;
	command_str = append_str(command_str, quoted, 0, ft_strlen(quoted));
	free(quoted);
	return (command_str);
}

char	*expand_token(const char *str)
{
	char	*command_str;
	size_t	i;
	size_t	j;

	command_str = NULL;
	i = 0;
	j = 0;
	while (str[i + j] != '\0')
	{
		if (ft_strchr("\'\"$", str[i + j]))
		{
			command_str = append_str(command_str, str, i, j);
			i = i + j + 1;
			j = 0;
			if (str[i - 1] == '\"')
				command_str = expand_doub_quote(command_str, str, &i);
			else if (str[i - 1] == '\'')
				command_str = expand_sing_quote(command_str, str, &i);
			else
				command_str = expand_env_var(command_str, str, &i);
		}
		else
			j++;
	}
	return (append_str(command_str, str, i, j));
}
