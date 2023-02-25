/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:15:59 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/21 17:16:55 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
//
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
