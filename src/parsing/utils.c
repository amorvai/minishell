/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 08:27:14 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/28 12:44:36 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../../lib/the_lib/lib.h"

char	*append_str(char *command_str,
					const char *str, size_t start, size_t len)
{
	char		*new_command_str;
	const char	*append;
	size_t		len_old;

	append = str + start;
	if (command_str)
		len_old = ft_strlen(command_str);
	else
		len_old = 0;
	new_command_str = ft_xcalloc(len_old + len + 1, sizeof(char));
	ft_memcpy(new_command_str, command_str, len_old);
	ft_strlcat(new_command_str, append, len_old + len + 1);
	if (command_str)
		free(command_str);
	return (new_command_str);
}

char	*expand_doub_quote_simple(char *command_str, const char *str, size_t *i)
{
	size_t	j;

	j = 0;
	while (str[*i + j] != '\"')
		j++;
	command_str = append_str(command_str, str, *i, j);
	*i = *i + j + 1;
	return (command_str);
}

char	*expand_heredoc(const char *line)
{
	char	*expanded_line;
	size_t	i;
	size_t	j;

	expanded_line = NULL;
	i = 0;
	j = 0;
	while (line[i + j] != '\0')
	{
		if (line[i + j] == '$')
		{
			expanded_line = append_str(expanded_line, line, i, j);
			i = i + j + 1;
			j = 0;
			expanded_line = expand_env_var(expanded_line, line, &i, false);
		}
		else
			j++;
	}
	return (append_str(expanded_line, line, i, j));
}
