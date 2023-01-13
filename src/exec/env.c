/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/01/13 14:24:59 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../env/env.h"

int bi_env(char *value)
{
	char *str;
	char **split;
	bool equal_sign;
	
	if (value == NULL)
		print_env();
	else
	{
		str = get_env(value);
		equal_sign = false;
		if (ft_strchr(str, '=') != NULL)
			equal_sign = true;
		if (str != NULL && equal_sign == false)
			ft_putstr_fd(str, 1);
		else if (equal_sign == true && str == NULL)
		{
			print_env();
			printf("%s\n", value);
		}
		else if (equal_sign == true && str != NULL)
		{
			split = ft_split(value, "=");
			add_env(split[0], split[1]);
			print_env();
		}
		else
		{
			printf("env: %s: No such file or directory", value);
			return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
}