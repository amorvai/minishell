/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:01:59 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/25 07:08:44 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../structure/command.h"
#include "../parsing/utils.h"
#include "../../lib/the_lib/lib.h"
#include "../signal/signals.h"
#include <unistd.h>
#include <fcntl.h>

static char	*expand_delimiter(const char *str)
{
	char	*command_str;
	size_t	i;
	size_t	j;

	command_str = NULL;
	i = 0;
	j = 0;
	while (str[i + j] != '\0')
	{
		if (ft_strchr("\'\"", str[i + j]))
		{
			command_str = append_str(command_str, str, i, j);
			i = i + j + 1;
			j = 0;
			if (str[i - 1] == '\"')
				command_str = expand_doub_quote_simple(command_str, str, &i);
			else if (str[i - 1] == '\'')
				command_str = expand_sing_quote(command_str, str, &i);
		}
		else
			j++;
	}
	if (i == 0)
		return (command_str);
	return (append_str(command_str, str, i, j));
}

static char	*expand_heredoc(const char *line)
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
			expanded_line = expand_env_var(expanded_line, line, &i);
		}
		else
			j++;
	}
	return (append_str(expanded_line, line, i, j));
}

static void	read_to_fd(int fd, const char *delim)
{
	char	*line;
	char	*exp_line;
	char	*exp_delim;

	exp_delim = expand_delimiter(delim);
	if (exp_delim)
		delim = exp_delim;
	while (1)
	{
		line = get_next_line(0);
		if (!line || ft_strncmp(line, delim, ft_strlen(delim)) == 0)
			break ;
		if (exp_delim)
			write(fd, line, ft_strlen(line));
		else
		{
			exp_line = expand_heredoc(line);
			write(fd, exp_line, ft_strlen(exp_line));
			free(exp_line);
		}
		free(line);
	}
	if (exp_delim)
		free(exp_delim);
}

int	create_tmp_file(char **filename)
{
	static int	i = 0;
	char		*number;

	number = ft_itoa(i);
	*filename = ft_xstrjoin("/tmp/miesmushell_heredoc", number);
	free(number);
	i++;
	return (open(*filename, O_WRONLY | O_CREAT | O_TRUNC, 0644));
}

char	*heredoc(const char *delim)
{
	int		fd;
	char	*filename;

	filename = NULL;
	terminal_switch("execute");
	fd = create_tmp_file(&filename);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	read_to_fd(fd, delim);
	close(fd);
	return (filename);
}
