/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:17:42 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/10 17:18:15 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../minishell/minishell.h"
#include "../env/env.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include "../../lib/the_lib/lib.h"
#include "../builtin/builtins.h"
#include "../parsing/parsing.h"

int command_and_counter(t_simp_com *head)
{
	int i;
	
	i = 0;
	while (head != NULL)
	{
		i++;
		head = head->next;
	}
	return (i);
}

static void fabricating_pipes(int amo_pipes, int fds[amo_pipes][2])
{
	int i;
	
	i = 0;
	while (i < amo_pipes)
	{
		pipe(fds[i]);
		i++;
	}
}

static void	the_closer(int amo_pipes, int fds[amo_pipes][2], int i, char *flex)
{
	int	z;
	
	z = 0;
	if (ft_strcmp("parent", flex) == 0)
	{
		while (z < amo_pipes)
		{
			close(fds[z][0]);
			close(fds[z][1]);
			z++;
		}
	}
	else if (ft_strcmp("child", flex) == 0)
	{
		while (z < amo_pipes)
		{
			if (z != i - 1)
				close(fds[z][0]);
			if (z != i)
				close(fds[z][1]);
			z++;
		}
	}
	// if (i == 0)
	// {
	// 	close(fds[0][0]);
	// 	// close(fds[0][1]);
	// 	close(fds[1][1]);
	// 	close(fds[1][1]);
	// }
	// if (i == amo_pipes)
	// {
	// 	// close(fds[0][0]);
	// 	close(fds[0][1]);
	// 	close(fds[1][0]);
	// 	close(fds[1][1]);
	// }
	// if (i != 0 && i != amo_pipes)
	// {
	// 	// close(fds[0][0]);
	// 	close(fds[0][1]);
	// 	close(fds[1][0]);
	// 	// close(fds[1][1]);
	// }
}

static void	childish_behaviour(t_simp_com *h, int a_p, int fds[a_p][2], int i)
{
	int j;
	
	j = 0;
	the_closer(a_p, fds, i, "child");
	// perror("Begin\n");
	while (h != NULL && j < i)
	{
		h = h->next;
		j++;
	}
	if (i != 0)
	{
		dup2(fds[i - 1][0], STDIN_FILENO);
		close(fds[i - 1][0]);	
	}
	if (i < a_p)
	{
		// perror("hey\n");
		dup2(fds[i][1], STDOUT_FILENO);
		close(fds[i][1]);
	}
	// perror("End\n");
	decisionmaker(h->command, "child");
}

void idle_mode(int amo_cmd)
{
	int status;
	
	while (amo_cmd > 0)
	{
		wait(&status);
		amo_cmd--;
	}
}

static void multiple_pipes(t_simp_com *head, int amo_pipes)
{
	pid_t		pids[10];
	int			fds[amo_pipes][2];
	int			amo_cmd;
	// int			**fds;
	int			i;

	// fds = malloc(sizeof(int *) * amo_pipe);
	// *fds = malloc(sizeof(int) * 2);
	i = 0;
	// printf("Amo_Pipes %d\n", amo_pipes);
	amo_cmd = amo_pipes + 1;
	fabricating_pipes(amo_pipes, fds);
	while(i < amo_cmd)
	{
		if ((pids[i] = fork()) < 0)
		{
			perror("Fork creation failed");
			exit(EXIT_FAILURE);
			//exit functions needs to be switched
		}
		else if (pids[i] == 0)
			childish_behaviour(head, amo_pipes, fds, i);
		i++;
	}
	the_closer(amo_pipes, fds, 0, "parent");
	idle_mode(amo_cmd);
	// dup2(fds[0][1], STDOUT_FILENO);
	// close(fds[0][1]);
	// decisionmaker(head->command, "parent");
	//this minus ONE so damn weird
}

void where_ma_pipes(t_simp_com *head)
{
	if (command_and_counter(head) > 0)
		multiple_pipes(head, command_and_counter(head) - 1);
	else
		decisionmaker(head->command,  "parent");
}
