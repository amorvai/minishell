/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rede.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:38:05 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/28 10:38:57 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../error/error.h"
#include "../structure/command.h"
#include "../../lib/the_lib/lib.h"

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>

int	open_dup_close(t_redirection *redir, int o_flags, int fd_to_change)
{
	redir->fd = open(redir->file, o_flags);
	if (redir->fd < 0)
		return (/*print_open_protection(), */1);
	dup2(redir->fd, fd_to_change);
	close(redir->fd);
	return (0);
}
//open calls need to be protected against directorys probably

static int	input_search(t_redirection *input)
{
	if (check_validity(input->file, NULL))
			return (1);
	if (input->next == NULL)
		if (open_dup_close(input, O_RDONLY, STDIN_FILENO))
			return (1);
	return (0);
}

static int	output_search(t_redirection *output)
{
	struct stat	s;
	
	if (stat(output->file, &s))
	{
		output->fd = open(output->file, O_WRONLY | O_CREAT, 0644);
		if (output->fd < 0)	
			return (/*print_open_protection(), */1);
		close(output->fd);
	}
	else if (!(s.st_mode & S_IWUSR))
		return (print_permission_denied(output->file), 1);
	if (output->next == NULL)
	{
		if (output->redir_type == GREAT)
		{
			if (open_dup_close(output, O_WRONLY | O_TRUNC, STDOUT_FILENO))
				return (1);
		}
		else
			if (open_dup_close(output, O_WRONLY | O_APPEND, STDOUT_FILENO))
				return (1);
	}
	return (0);
}
	// if (output->redir_type == GREAT && output->next == NULL)
	// else if (output->redir_type == GGREAT && output->next == NULL)

int	redirector(t_simp_com **single_cmd)
{
	t_redirection	*redirection;
	
	redirection = (*single_cmd)->redirect_input;
	while (redirection != NULL)
	{
		if (input_search(redirection))
			return (EXIT_FAILURE);
		redirection = redirection->next;
	}
	redirection = (*single_cmd)->redirect_output;
	while (redirection != NULL)
	{
		if (output_search(redirection))
			return (EXIT_FAILURE);
		redirection = redirection->next;
	}
	return (EXIT_SUCCESS);
}
