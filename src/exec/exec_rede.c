/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rede.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:38:05 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/16 16:28:15 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../structure/command.h"
#include "../../lib/the_lib/lib.h"

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int	input_search(t_redirection *input)
{
	struct	stat s;

	if (input->redir_type == LESS || input->redir_type == LLESS)
	{
		//stat call needs to be changed, it doesnt catch directorys
		if (stat(input->file, &s) != 0)
		{
			// we should have an error handler
			ft_putstr_fd("🐚: ", 2);
			ft_putstr_fd(input->file, 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			return (EXIT_FAILURE);
		}
		else if(input->next == NULL)
		{
			input->fd = open(input->file, O_RDONLY);
			dup2(input->fd, STDIN_FILENO);
			close(input->fd);
		}
		//open calls need to be protected against directorys probably
	}
	return (EXIT_SUCCESS);
}

void	output_search(t_redirection *output)
{
	struct	stat s;

	if (stat(output->file, &s) != 0)
	{
		output->fd = open(output->file, O_RDWR | O_CREAT, 0644);
		close(output->fd);
	}
	if (output->redir_type == GREAT)
	{
		if (output->next == NULL)
		{
			output->fd = open(output->file, O_RDWR);
			dup2(output->fd, STDOUT_FILENO);
			close(output->fd);
		}
		//open calls need to be protected against directorys probably
	}
	else if (output->redir_type == GGREAT)
	{
		if (output->next == NULL)
		{
			output->fd = open(output->file, O_RDWR | O_APPEND);
			dup2(output->fd, STDOUT_FILENO);
			close(output->fd);
		}
	}
}

int	where_ma_redirec(t_simp_com *single_cmd)
{
	t_redirection	*redirection;

	redirection = single_cmd->redirect_input;
	while (redirection != NULL)
	{
		if (input_search(redirection) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		redirection = redirection->next;
	}
	redirection = single_cmd->redirect_output;
	while (redirection != NULL)
	{
		output_search(redirection);
		redirection = redirection->next;
	}
	return (EXIT_SUCCESS);
}
