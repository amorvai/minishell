/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:28:52 by amorvai           #+#    #+#             */
/*   Updated: 2022/06/25 23:50:44 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*mem;

	if (lst != NULL)
	{
		while (*lst != NULL)
		{
			del((*lst)->content);
			mem = (*lst)->next;
			free(*lst);
			*lst = mem;
		}
		lst = NULL;
	}
}
