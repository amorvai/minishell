/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:17:42 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/08 19:13:41 by pnolte           ###   ########.fr       */
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
	while (head->next != NULL)
	{
		i++;
		head = head->next;
	}
	return (i);
}

// static void one_pipe(t_simp_com *head, int simp_l)
// {
// 	// t_simp_com *copy;
// 	pid_t pid;
// 	int fds[2];
	
// 	pipe(fds);
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		dup2(fds[0], STDIN_FILENO);
// 		close(fds[0]);
// 		close(fds[1]);
// 		head = head->next;
// 		decisionmaker(head->command);
// 	}
// 	close(fds[0]);
// 	// printf("parent\n");
// 	dup2(fds[1], STDOUT_FILENO);
// 	decisionmaker(head->command);
// 	close(fds[1]);
// 	waitpid(pid, &simp_l, 0);
// }

static void multiple_pipes(t_simp_com *head, int simp_l)
{
	pid_t pids[10];
	t_simp_com *copy;
	int fds[simp_l][2];
	int prevfds[2];
	int i;
	int j;
	int status;

/* Start children. */
	// printf("%d\n", simp_l);
	i = 0;
	while (i < simp_l)
	{
		pipe(fds[i]);
		// printf("I:%d\n", i);
		i++;
	}
	prevfds[0] = -1;
	prevfds[1] = -1;
	i = 0;
	while(i < simp_l)
	{
		if ((pids[i] = fork()) < 0)
		{
			perror("Fork creation failed");
			exit(EXIT_FAILURE);
			//exit functions needs to be switched
		}
		else if (pids[i] == 0)
		{
			int z = 0;
			while (z < simp_l)
			{
				if (z != i)
					close(fds[z][0]);
				if (z != i + 1)
					close(fds[z][1]);
				// if (z == simp_l - 1)
				// 	close(fds[z][1]);
				z++;
			}
			copy = head->next;
			j = 0;
			while (copy != NULL && j < i)
			{
				copy = copy->next;
				j++;
			}
			dup2(fds[i][0], STDIN_FILENO);
			// printf("FORK:%d\n", i);
			if (i != simp_l - 1)
			{
				// printf("hi");
				dup2(fds[i + 1][1], STDOUT_FILENO);
			}
			// printf("Child: %s %s | I:%d\n", copy->command[0], copy->command[1], i);
			close(fds[i][0]);
			if (i != simp_l - 1)
				close(fds[i + 1][1]);
			decisionmaker(copy->command);
		}
		i++;
	}
	close(fds[0][0]);
	close(fds[1][0]);
	// printf("parent\n");
	// printf("Parent: %s\n", head->command[0]);
	dup2(fds[0][1], STDOUT_FILENO);
	close(fds[0][1]);
	close(fds[1][1]);
	decisionmaker(head->command);
	while (simp_l > 0)
	{
		wait(&status);
		simp_l--;
	}
}

void where_ma_pipes(t_simp_com *head)
{
	if (command_and_counter(head) > 0)
		multiple_pipes(head, command_and_counter(head));
	else
		decisionmaker(head->command);
}