/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rede.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:38:05 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/24 16:19:59 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../error/error.h"
#include "../structure/command.h"
#include "../../lib/the_lib/lib.h"

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

static int	permission_to_do(char *file)
{
	struct stat		s;

	if (stat(file, &s))
		return (print_no_such(file, "file_or_dire"));
	if (!(s.st_mode & S_IRUSR))
		return(print_permission_denied(file));
	return(EXIT_SUCCESS);
}

static int	input_search(t_redirection *input)
{
	//stat call needs to be changed, it doesnt catch directorys
	if (input->next == NULL)
	{
		input->fd = open(input->file, O_RDONLY);
		dup2(input->fd, STDIN_FILENO);
		close(input->fd);
	}
	//open calls need to be protected against directorys probably
	return (EXIT_SUCCESS);
}

static int	output_search(t_redirection *output)
{
	struct stat		s;
	
	if (stat(output->file, &s))
	{
		output->fd = open(output->file, O_WRONLY | O_CREAT, 0644);
		close(output->fd);
	}
	else if (!(s.st_mode & S_IWUSR))
		return(print_permission_denied(output->file));
	if (output->redir_type == GREAT)
	{
		if (output->next == NULL)
		{
			output->fd = open(output->file, O_WRONLY | O_TRUNC);
			dup2(output->fd, STDOUT_FILENO);
			close(output->fd);
		}
		//open calls need to be protected against directorys probably
	}
	else if (output->redir_type == GGREAT)
	{
		if (output->next == NULL)
		{
			output->fd = open(output->file, O_WRONLY | O_APPEND);
			dup2(output->fd, STDOUT_FILENO);
			close(output->fd);
		}
	}
	return (EXIT_SUCCESS);
}

int	where_ma_redirec(t_simp_com *single_cmd)
{
	t_redirection	*redirection;
	
	redirection = single_cmd->redirect_input;
	while (redirection != NULL)
	{
		if (permission_to_do(redirection->file) != 0)
			return(EXIT_FAILURE);
		if (input_search(redirection))
			return (EXIT_FAILURE);
		redirection = redirection->next;
	}
	redirection = single_cmd->redirect_output;
	while (redirection != NULL)
	{
		if (output_search(redirection))
			return (EXIT_FAILURE);
		redirection = redirection->next;
	}
	return (EXIT_SUCCESS);
}
