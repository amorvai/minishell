/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:03:04 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/13 11:42:21 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../../lib/the_lib/lib.h"

t_redirection	*extract_redirection(t_token *temp_lst)
{
	t_redirection	*new_redir;

	new_redir = ft_calloc(1, sizeof(t_redirection));
	new_redir->redir_type = temp_lst->token;
	new_redir->file	= expand_token(temp_lst->next->word);
	return (new_redir);
}

void	redir_add_back(t_redirection **lst, t_redirection *new_elem)
{
	t_redirection	*tmp;

	// ft_printf("redir_addt: %s\n", new_elem->file);
	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			tmp = *lst;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new_elem;
		}
		else
			*lst = new_elem;
	}
}

void	print_redirection(t_redirection *redirection)
{
	t_redirection	*temp;

	temp = redirection;
	while (temp)
	{
		ft_printf("redirection:\t");
		if (temp->redir_type == 2)
			ft_printf("> ");
		else if (temp->redir_type == 3)
			ft_printf("< ");
		else if (temp->redir_type == 4)
			ft_printf(">>");
		else if (temp->redir_type == 5)
			ft_printf("<<");
		ft_printf(" %s\n", temp->file);
		temp = temp->next;
	}
}
