/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:41:55 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/13 11:41:52 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../../lib/the_lib/lib.h"

void	command_add_back(t_simp_com **lst, t_simp_com *new_elem)
{
	t_simp_com	*tmp;

	if (lst != NULL)
	{
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
}

void	free_str_arr(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

static void	free_redirection(t_redirection *redirections)
{
	t_redirection *temp;

	while (redirections)
	{
		if (redirections->file)
			free(redirections->file);
		temp = redirections->next;
		free(redirections);
		redirections = temp;
	}
}

void	command_clear(t_simp_com **lst)
{
	t_simp_com	*mem;

	if (lst != NULL)
	{
		while (*lst != NULL)
		{
			free_str_arr((*lst)->command);
			free_redirection((*lst)->redirect_input);
			free_redirection((*lst)->redirect_output);
			mem = (*lst)->next;
			free(*lst);
			*lst = mem;
		}
	}
}

void	print_commands(t_simp_com *command)
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
