/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:03:04 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/23 10:41:00 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"
#include <stdlib.h>
#include <stdio.h>

void	redir_add_back(t_redirection **lst, t_redirection *new_elem)
{
	t_redirection	*tmp;

	if (*lst)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_elem;
	}
	else
		*lst = new_elem;
}

void	free_redirection(t_redirection *redirections)
{
	t_redirection	*temp;

	while (redirections)
	{
		if (redirections->file)
			free(redirections->file);
		temp = redirections->next;
		free(redirections);
		redirections = temp;
	}
}

void	print_redirection(t_redirection *redirection)
{
	t_redirection	*temp;

	temp = redirection;
	while (temp)
	{
		printf("redirection:\t");
		if (temp->redir_type == 2)
			printf("> ");
		else if (temp->redir_type == 3)
			printf("< ");
		else if (temp->redir_type == 4)
			printf(">>");
		else if (temp->redir_type == 5)
			printf("<<");
		printf(" %s\n", temp->file);
		temp = temp->next;
	}
}
