/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 00:32:51 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/23 10:38:16 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdlib.h>
#include <stdio.h>

void	token_lst_add_back(t_token **lst, t_token *new_token)
{
	t_token	*tmp;

	if (*lst)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_token;
		new_token->prev = tmp;
	}
	else
		*lst = new_token;
}

void	token_delete(t_token **lst, t_token *tobedeleted)
{
	if (!tobedeleted->prev)
	{
		*lst = (*lst)->next;
		if (*lst)
			(*lst)->prev = NULL;
	}
	else
	{
		tobedeleted->prev->next = tobedeleted->next;
		if (tobedeleted->next)
			tobedeleted->next->prev = tobedeleted->prev;
	}
	if (tobedeleted->word)
		free(tobedeleted->word);
	free(tobedeleted);
}

void	token_lst_clear(t_token **lst)
{
	t_token	*mem;

	while (*lst)
	{
		if ((*lst)->word)
			free((*lst)->word);
		mem = (*lst)->next;
		free(*lst);
		*lst = mem;
	}
}

void	free_token_lst_array(t_token **token_lst_array, int array_len)
{
	int	i;

	i = 0;
	while (i < array_len)
	{
		token_lst_clear(&token_lst_array[i]);
		i++;
	}
	free(token_lst_array);
}

void	token_lst_print(t_token *token_lst)
{
	while (token_lst)
	{
		if (token_lst->token == WORD)
			printf("WORD:\t%s\n", token_lst->word);
		if (token_lst->token == PIPE)
			printf("PIPE:\t|\n");
		if (token_lst->token == GREAT)
			printf("GREAT:\t>\n");
		if (token_lst->token == LESS)
			printf("LESS:\t<\n");
		if (token_lst->token == GGREAT)
			printf("GGREAT:\t>>\n");
		if (token_lst->token == LLESS)
			printf("LLESS:\t<<\n");
		token_lst = token_lst->next;
	}
	printf("NO MORE TOKENS\n\n");
}
