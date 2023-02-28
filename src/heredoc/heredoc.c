/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:01:59 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/28 11:59:29 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../structure/command.h"
#include "../parsing/utils.h"
#include "../../lib/the_lib/lib.h"
#include "../signal/signals.h"
#include "../exec/exec.h"
#include "../builtin/builtins.h"
#include "../error/error.h"
#include "../env/env.h"

#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>

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

static void write_to_file(int fd, char *line, char **exp_line, char *exp_delim)
{
	if (exp_delim)
		write(fd, line, ft_strlen(line));
	else
	{
		*exp_line = expand_heredoc(line);
		write(fd, *exp_line, ft_strlen(*exp_line));
		free(*exp_line);	
	}
}

static int	read_to_fd(int fd, const char *delim)
{
	char	*line;
	char	*exp_line;
	char	*exp_delim;
	int		rvalue;
	
	sigact_heredoc();
	exp_delim = expand_delimiter(delim);
	if (exp_delim)
		delim = exp_delim;
	while (1)
	{
		line = NULL;
		rvalue = get_next_line(0, &line);
		if (!line || (ft_strncmp(line, delim, ft_strlen(delim)) == 0 &&	
			ft_strlen(line) == ft_strlen(delim) + 1) || rvalue != 0)
			break ;
		write_to_file(fd, line, &exp_line, exp_delim);
		free(line);
	}
	if (exp_delim)
		free(exp_delim);
	if (line)
		free(line);
	return(rvalue);
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
	int		fd[2];
	char	*filename;

	filename = NULL;
	fd[0] = create_tmp_file(&filename);
	if (ft_strcmp(get_env("42heredoc"), "used") == 0)
		return (filename);
	if (fd[0] == -1)
		exit(print_open_protection());
	if (read_to_fd(fd[0], delim) != 0)
	{
		fd[1] = open(filename, O_WRONLY | O_TRUNC, 0644);
		close(fd[1]);
	}
	close(fd[0]);
	return (filename);
}
