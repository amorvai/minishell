/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:47:14 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/18 08:31:23 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../env/env.h"
#include "../../lib/the_lib/lib.h"
#include <stdio.h> // for NULL

static char	*get_key_name(char *str, int i)
{
	int	j;

	j = 0;
	while (str[i + j] != '\0' && !ft_strchr("\'\"$ \t\n", str[i + j])) // do I need to respect tabs/newlines
		j++;
	if (j > 0)
		return (ft_substr(str, i, j));
	return (NULL);
}

static void	expand_env_var(char **command_str, char *str, size_t *i)
{
	char	*env_key;
	char	*env_value;

	env_key = get_key_name(str, *i);
	if (!env_key)
	{
		append_str(command_str, "$", 0, 1);
		return ;
	}
	env_value = get_env(env_key);
	if (env_value)
		append_str(command_str, env_value, 0, ft_strlen(env_value));
	*i = *i + ft_strlen(env_key);
	free(env_key);
}

static void	expand_sing_quote(char **command_str, char *str, size_t *i)
{
	size_t	j;

	j = 0;
	while (str[*i + j] != '\'')
		j++;
	append_str(command_str, str, *i, j);
	*i = *i + j + 1;
}

static void	expand_doub_quote(char **command_str, char *str, size_t *i)
{
	char	*quoted;
	size_t	j;

	quoted = NULL;
	j = 0;
	while (str[*i + j] != '\"')
	{
		if (str[*i + j] == '$')
		{
			append_str(&quoted, str, *i, j);
			*i = *i + j + 1;
			j = 0;
			expand_env_var(&quoted, str, i);
		}
		else
			j++;
	}
	append_str(&quoted, str, *i, j);
	*i = *i + j + 1;
	append_str(command_str, quoted, 0, ft_strlen(quoted));
	free(quoted);
}

char	*expand_token(char *str)
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
			append_str(&command_str, str, i, j);
			i = i + j + 1;
			j = 0;
			if (str[i - 1] == '\"')
				expand_doub_quote(&command_str, str, &i);
			else if (str[i - 1] == '\'')
				expand_sing_quote(&command_str, str, &i);
			else
				expand_env_var(&command_str, str, &i);
		}
		else
			j++;
	}
	append_str(&command_str, str, i, j);
	return (command_str);
} // one line too much, still
