/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:07:59 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/17 14:05:31 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <stdio.h>
#include "../../lib/the_lib/lib.h"

int	main()
{
	int i;
	
	i = 0;
	init_env();
	print_env();
	add_env(ft_strdup("hello=hello"));
	add_env(ft_strdup("nice=nice"));
	add_env(ft_strdup("TEST=TEST:$hello"));
	print_env();
	del_env("TEST");
	ft_printf("\n");
	print_env();
	
	// ft_printf("get_env(\"hello\"): %s\n", get_env("hello"));
	// ft_printf("get_env(\"HOME\"): %s\n", get_env("HOME"));
	
	// printf("\n\n shouldve\n\n");
	// while (environ[i] != NULL)
	// {
	// 	printf("%s\n", environ[i]);
	// 	i++;
	// }
	
	return (0);
}
