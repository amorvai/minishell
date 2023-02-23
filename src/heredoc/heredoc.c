/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:01:59 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/23 16:53:28 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../structure/command.h"
#include "../parsing/utils.h"
#include "../../lib/the_lib/lib.h"

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

static void	read_to_fd(int fd, char *delim)
{
	char	*line;
	char	*expanded_line;

	while (1)
	{
		line = get_next_line(0);
		if (!line || ft_strncmp(line, delim, ft_strlen(delim)) == 0)
			break ;
		expanded_line = expand_heredoc(line);
		free(line);
		write(fd, expanded_line, ft_strlen(expanded_line));
		free(expanded_line);
	}
}

int	foo(t_redirection *redir, int fd[2])
{
	
}

int	heredoc(t_simp_com *command)
{
	int	i;

	i = 0;
	while (command)
	{
		if (command->redirect_input)
			foo(command->redirect_input, fd[i - 1]);
		command = command->next;
		i++;
	}
}
