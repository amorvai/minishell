/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:01:56 by pnolte            #+#    #+#             */
/*   Updated: 2023/01/10 15:47:15 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void bi_echo(char *string, int flag)
{
	int i;

	i = 0;
	if (flag == 0)
	{
		ft_putstr_fd(string, 1);
		ft_putchar_fd('\n', 1);
	}
	else
		ft_putstr_fd(string, 1);
}

void bi_cd(char *path)
{
	
}

void bi_pwd()
{
	get_env
}

void bi_export()
{
	
}