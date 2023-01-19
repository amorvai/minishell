/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/01/19 16:21:15 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env/env.h"
#include "../../lib/the_lib/lib.h"
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int bi_env(char **simple_command)
{
	//ft_strcmp needs to be not casesensetiv
	if (ft_strcmp(simple_command[1], "pwd") == 0)
	{
		ft_putstr_fd(get_env("PWD"), 1);
		return (EXIT_SUCCESS);
	}
	else if (simple_command[1] != NULL)
	{
		printf("env: %s: No such file or directory", simple_command[1]);
		return (EXIT_FAILURE);
	}
	else
		print_env();
	return(EXIT_SUCCESS);
		
	// char *str;
	// char **split;
	// bool equal_sign;
	
	// if (simple_command[0] == NULL)
	// 	print_env();
	// else
	// {
	// 	str = get_env(simple_command[0]);
	// 	equal_sign = false;
	// 	if (ft_strchr(str, '=') != NULL)
	// 		equal_sign = true;
	// 	if (str != NULL && equal_sign == false)
	// 		ft_putstr_fd(str, 1);
	// 	else if (equal_sign == true && str == NULL)
	// 	{
	// 		print_env();
	// 		printf("%s\n", simple_command[0]);
	// 	}
	// 	else if (equal_sign == true && str != NULL)
	// 	{
	// 		split = ft_split(simple_command[0], "=");
	// 		add_env(split[0], split[1]);
	// 		print_env();
	// 	}
	// 	else
	// 	{
	// 		printf("env: %s: No such file or directory", simple_command[0]);
	// 		return (EXIT_FAILURE);
	// 	}
	// }
}