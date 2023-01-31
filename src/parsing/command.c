/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:41:55 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/31 17:50:05 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	command_add_back(t_simp_com **lst, t_simp_com *new_elem)
{
	t_simp_com	*tmp;

	if (lst != NULL)
	{
		if (*lst != NULL)
		{
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
