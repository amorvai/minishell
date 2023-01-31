/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 00:32:51 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/19 18:06:59 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/the_lib/lib.h"
#include "token.h"
#include <stdlib.h>

// t_token	*tokenlast(t_token *lst)
// {
// 	if (lst == NULL)
// 		return (NULL);
// 	while (lst->next != NULL)
// 		lst = lst->next;
// 	return (lst);
// }


// void	token_delete(t_token **lst, t_token *tobedeleted)
// {
// 	t_token	*tmp;

// 	if (*lst == tobedeleted)
// 	{
// 		if ((*lst)->next)
// 			*lst = (*lst)->next;
// 		(*lst)->prev = NULL;
// 	}
// 	else
// 	{
// 		tmp = *lst;
// 		while (tmp->next != NULL)
// 		{
// 			if (tmp->next == tobedeleted)
// 			{
// 				tmp->next = tmp->next->next;
// 				if (tmp->next)
// 					tmp->next->prev = tmp;
// 			}
// 			tmp = tmp->next;
// 		}
// 	}
// 	if (tobedeleted->word)
// 		free(tmp->word);
// 	free(tobedeleted);
// }



void	token_delete(t_token **lst, t_token *tobedeleted)
{
	t_token	*tmp;

	if (tobedeleted->prev == NULL)
	{
		*lst = (*lst)->next;
		if (*lst)
			(*lst)->prev = NULL;
	}
	else
	{
		tobedeleted->prev->next = tobedeleted->next;
		if (tobedeleted->next != NULL)
			tobedeleted->next->prev = tobedeleted->prev;
	}
	if (tobedeleted->word)
		free(tmp->word);
	free(tobedeleted);
}

void	tokenadd_back(t_token **lst, t_token *new_token)
{
	t_token	*tmp;

	if (*lst != NULL)
	{
		// tmp = tokenlast(*lst);

		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_token;
		new_token->prev = tmp;
	}
	else
		*lst = new_token;
}

void	tokenclear(t_token **lst)
{
	t_token	*mem;

	if (lst != NULL)
	{
		while (*lst != NULL)
		{
			if ((*lst)->word)
				free((*lst)->word);
			mem = (*lst)->next;
			free(*lst);
			*lst = mem;
		}
	}
}

void	token_lst_print(t_token *token_lst)
{
	while (token_lst)
	{
		if (token_lst->token == WORD)
			ft_printf("WORD:\t%s\n", token_lst->word);
		if (token_lst->token == PIPE)
			ft_printf("PIPE:\t|\n");
		if (token_lst->token == GREAT)
			ft_printf("GREAT:\t>\n");
		if (token_lst->token == LESS)
			ft_printf("LESS:\t<\n");
		if (token_lst->token == GGREAT)
			ft_printf("GGREAT:\t>>\n");
		if (token_lst->token == LLESS)
			ft_printf("LLESS:\t<<\n");
		token_lst = token_lst->next;
	}
}
