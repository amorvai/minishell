/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rede.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:38:05 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/20 16:16:22 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../structure/command.h"
#include "../../lib/the_lib/lib.h"

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

static int	permission_to_do(struct stat s, char *file, char *flex, int e)
{
	if ((e == 0 && ft_strcmp(flex, "input") == 0 && s.st_mode & S_IRUSR) || 
		(e == 0 && ft_strcmp(flex, "output") == 0 && s.st_mode & S_IWUSR))
		return(EXIT_SUCCESS);
	else
	{
		ft_putstr_fd("🐚: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		return(EXIT_FAILURE);
	}
}

static int	input_search(t_redirection *input, int existence)
{
	if (input->redir_type == LESS)
	{
		//stat call needs to be changed, it doesnt catch directorys
		if (existence != 0)
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

static int	output_search(t_redirection *output, int existence)
{
	if (existence != 0)
	{
		output->fd = open(output->file, O_WRONLY | O_CREAT, 0644);
		close(output->fd);
	}
	if (output->redir_type == GREAT)
	{
		if (output->next == NULL)
		{
			output->fd = open(output->file, O_WRONLY);
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
	struct stat		s;
	int				existence;

	redirection = single_cmd->redirect_input;
	while (redirection != NULL)
	{
		existence = stat(redirection->file, &s);
		if (permission_to_do(s, redirection->file, "input", existence) != 0)
			return(EXIT_FAILURE);
		if (input_search(redirection, existence) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		redirection = redirection->next;
	}
	redirection = single_cmd->redirect_output;
	while (redirection != NULL)
	{
		existence = stat(redirection->file, &s);
		if (permission_to_do(s, redirection->file, "output", existence) != 0)
			return(EXIT_FAILURE);
		output_search(redirection, existence);
		redirection = redirection->next;
	}
	return (EXIT_SUCCESS);
}
