/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:07:59 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/07 16:30:58 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <stdio.h>

extern char	**environ;

int	main()
{
	int i;

	i = 0;
	init_env();
	add_env("hello", "you");
	printf("ZDOTDIR value: %s\n---------------\n", get_env("ZDOTDIR"));
	print_env();
	printf("\n\n");
	add_env("SECURITYSESSIONID", "youthoughtBITCH");
	del_env("tihihihihi");
	del_env("ZDOTDIR");
	printf("ZDOTDIR value: %s\n---------------\n", get_env("ZDOTDIR"));
	print_env();
	free_env();
	print_env();
	// printf("\n\n shouldve\n\n");
	// while (environ[i] != NULL)
	// {
	// 	printf("%s\n", environ[i]);
	// 	i++;
	// }
	
	return (0);
}
