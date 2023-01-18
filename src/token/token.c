/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 00:32:51 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/16 21:48:05 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/the_lib/lib.h"
#include "token.h"
#include <stdlib.h>

t_token	*tokenlast(t_token *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	tokenadd_back(t_token **lst, t_token *new)
{
	t_token	*tmp;

	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			tmp = tokenlast(*lst);
			tmp->next = new;
			new->prev = tmp;
		}
		else
			*lst = new;
	}
}

void	tokenclear(t_token **lst)
{
	t_token	*mem;

	if (lst != NULL)
	{
		while (*lst != NULL)
		{
			free((*lst)->word);
			mem = (*lst)->next;
			free(*lst);
			*lst = mem;
		}
	}
}

void	tokens_print(t_token *tokens)
{
	while (tokens)
	{
		if (tokens->token == WORD)
			ft_printf("WORD:\t%s\n", tokens->word);
		if (tokens->token == PIPE)
			ft_printf("PIPE:\t|\n");
		if (tokens->token == GREAT)
			ft_printf("GREAT:\t>\n");
		if (tokens->token == LESS)
			ft_printf("LESS:\t<\n");
		if (tokens->token == GGREAT)
			ft_printf("GGREAT:\t>>\n");
		if (tokens->token == LLESS)
			ft_printf("LLESS:\t<<\n");
		tokens = tokens->next;
	}
}
