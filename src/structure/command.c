/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:41:55 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/23 10:41:25 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "redirection.h" // free_redirection / print_redirection
#include "../../lib/the_lib/lib.h" // free_splits
#include <stdlib.h> // free
#include <stdio.h> // printf

int	command_lst_len(t_simp_com *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void	command_lst_add_back(t_simp_com **lst, t_simp_com *new_elem)
{
	t_simp_com	*tmp;

	if (*lst)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_elem;
		new_elem->prev = tmp;
	}
	else
		*lst = new_elem;
}

void	command_lst_clear(t_simp_com **lst)
{
	t_simp_com	*mem;

	while (*lst)
	{
		free_splits((*lst)->command);
		free_redirection((*lst)->redirect_input);
		free_redirection((*lst)->redirect_output);
		mem = (*lst)->next;
		free(*lst);
		*lst = mem;
	}
}

void	print_command_lst(t_simp_com *command)
{
	int	i;
	int	j;

	j = 0;
	while (command)
	{
		i = 0;
		printf("t_simp_com no. %i\n------------\n", j);
		while (command->command[i])
		{
			printf("command[%i]\t%s\n", i, command->command[i]);
			i++;
		}
		print_redirection(command->redirect_input);
		print_redirection(command->redirect_output);
		command = command->next;
		if (command)
			printf("=== (pipe)\n");
		j++;
	}
}
