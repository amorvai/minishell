/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:07:59 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/25 12:03:15 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <stdio.h>
#include "../../lib/the_lib/lib.h"

int	main(void)
{
	int	i;

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
	return (0);
}

	// ft_printf("get_env(\"hello\"): %s\n", get_env("hello"));
	// ft_printf("get_env(\"HOME\"): %s\n", get_env("HOME"));

	// printf("\n\n shouldve\n\n");
	// while (environ[i] != NULL)
	// {
	// 	printf("%s\n", environ[i]);
	// 	i++;
	// }
