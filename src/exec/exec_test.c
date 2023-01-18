/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:17:53 by pnolte            #+#    #+#             */
/*   Updated: 2023/01/18 16:42:26 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
// #include "../../lib/the_lib/libft/libft.h"

int main()
{
	t_list *head;
	t_list *new;
	
	if (init_env() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	head = ft_lstnew("ls");
	new = ft_lstnew("-l");
	ft_lstadd_back(&head, new);
	executer(&head);
	// printf("FirstEntry:%s", head->content);
	// printf("SecondEntry:%s", head->next->content);
	
}