/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_protection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:56:14 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/27 15:54:29 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/the_lib/lib.h"
#include "../env/env.h"

int print_fork_protection()
{
	add_env(ft_strdup("?=1"));
	ft_putstr_fd("miesmushell: Fork creation failed", 2);
	return(EXIT_FAILURE);
}

int print_redirection_protection()
{
	add_env(ft_strdup("?=1"));
	ft_putstr_fd("miesmushell: Redirection failed", 2);
	return(EXIT_FAILURE);
}

int print_open_protection()
{
	add_env(ft_strdup("?=1"));
	ft_putstr_fd("miesmushell: Open failed", 2);
	return(EXIT_FAILURE);
}

