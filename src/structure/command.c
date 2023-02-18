/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:41:55 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/18 10:52:08 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "redirection.h" // free_redirection
#include "../../lib/the_lib/lib.h" // ft_printf / free_splits

int command_lst_len(t_simp_com *head)
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

void	command_lst_add_back(t_simp_com **lst, t_simp_com *new_elem)
{
	t_simp_com	*tmp;

	if (*lst != NULL)
	{
		tmp = *lst;
		while (tmp->next != NULL)
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

	if (lst != NULL)
	{
		while (*lst != NULL)
		{
			free_splits((*lst)->command);
			free_redirection((*lst)->redirect_input);
			free_redirection((*lst)->redirect_output);
			mem = (*lst)->next;
			free(*lst);
			*lst = mem;
		}
	}
}

void	print_command_lst(t_simp_com *command)
{
	int	i;

	while (command)
	{
		i = 0;
		while (command->command[i])
		{
			ft_printf("command[%i]\t%s\n", i, command->command[i]);
			i++;
		}
		print_redirection(command->redirect_input);
		print_redirection(command->redirect_output);
		command = command->next;
		if (command)
			ft_printf("=== (pipe)\n");
	}
}
