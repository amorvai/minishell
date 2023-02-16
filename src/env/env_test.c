/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:07:59 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/16 14:48:12 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <stdio.h>
#include "../../lib/the_lib/lib.h"

extern char	**environ;

int	main()
{
	int i;
	
	i = 0;
	init_env();
	print_env();
	add_env("hello=hello");
	del_env("USER");
	ft_printf("\n");
	print_env();
	ft_printf("get_env(\"hello\"): %s\n", get_env("hello"));
	ft_printf("get_env(\"HOME\"): %s\n", get_env("HOME"));
	
	// printf("\n\n shouldve\n\n");
	// while (environ[i] != NULL)
	// {
	// 	printf("%s\n", environ[i]);
	// 	i++;
	// }
	
	return (0);
}
