/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_rede.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:38:05 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/14 19:24:40 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../parsing/parsing.h"
#include "../../lib/the_lib/lib.h"

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

void	can_redirection_close()
{
	printf("hi");
}

void where_ma_redirec(t_simp_com *cmds)
{
	int i;
	t_simp_com *copy;
	t_redirection *c_r;
	struct stat s;
	
	
	i = 0;
	copy = cmds;
	while (copy != NULL)	
	{
		c_r = copy->redirect_input;
		// ft_putstr_fd("you come here", 2);
		while (c_r != NULL)
		{
			if (c_r->redir_type == LESS)
			{
				//stat call needs to be changed, it doesnt catch directorys
				if (stat(c_r->file, &s) != 0)
				{
					// we should have an error handler
					ft_putstr_fd("🐚: ", 2);
					ft_putstr_fd(c_r->file, 2);
					ft_putstr_fd(": No such file or directory\n", 2);
					return ;
				}
				else if(c_r->next == NULL)
				{
					c_r->fd = open(c_r->file, O_RDONLY);
					dup2(c_r->fd, STDIN_FILENO);
				}	
				//open calls need to be protected against directorys probably
			}
			else if (c_r->redir_type == LLESS)
			{
				printf("not implemented yet :D");
			}
			c_r = c_r->next;
		}
		c_r = copy->redirect_output;
		while (c_r != NULL)
		{
			if (stat(c_r->file, &s) != 0)
			{
				c_r->fd = open(c_r->file, O_RDWR | O_CREAT);
				close(c_r->fd);
			}
			if (c_r->redir_type == GREAT)
			{
				if(c_r->next == NULL)
				{
					c_r->fd = open(c_r->file, O_WRONLY);
					dup2(c_r->fd, STDOUT_FILENO);
				}
				//open calls need to be protected against directorys probably
			}
			else if (c_r->redir_type == GGREAT)
			{
				if(c_r->next == NULL)
				{
					c_r->fd = open(c_r->file, O_WRONLY | O_APPEND);
					// lseek(c_r->fd, 0, SEEK_END);
					dup2(c_r->fd, STDOUT_FILENO);
				}
			}
			c_r = c_r->next;
		}
		copy = copy->next;
	}
}