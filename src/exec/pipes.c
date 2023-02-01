/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:17:42 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/01 19:07:22 by pnolte           ###   ########.fr       */
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
	int fds[2];
	// int prevfds[2];
	int i;
	int j;
	int status;

/* Start children. */
	// printf("%d\n", simp_l);
	i = 0;
	// prevfds[0] = -1;
	// prevfds[1] = -1;
	pipe(fds);
	while(i < simp_l)
	{
		if ((pids[i] = fork()) < 0)
		{
			perror("Fork creation failed");
			exit(EXIT_FAILURE);
		}
		else if (pids[i] == 0)
		{
			if (i != 0)
			{
				printf("%d", pids[i - 1]);
				waitpid(pids[i - 1], &status, 0);
			}
			copy = head->next;
			dup2(fds[0], STDIN_FILENO);
			// printf("FORK:%d\n", i);
			if (i != simp_l - 1)
				dup2(fds[1], STDOUT_FILENO);
			j = 0;
			while (copy != NULL && j < i)
			{
				copy = copy->next;
				j++;
			}
			printf("Child: %s %s\n", copy->command[0], copy->command[1]);
			close(fds[0]);
			close(fds[1]);
			decisionmaker(copy->command);
		}
		i++;
	}
	close(fds[0]);
	// printf("parent\n");
	// printf("Parent: %s\n", head->command[0]);
	dup2(fds[1], STDOUT_FILENO);
	close(fds[1]);
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