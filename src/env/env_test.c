/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:07:59 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/13 17:36:12 by pnolte           ###   ########.fr       */
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
	print_env();
	printf("\n%s\n", get_env("PWD"));
	// printf("\n\n shouldve\n\n");
	// while (environ[i] != NULL)
	// {
	// 	printf("%s\n", environ[i]);
	// 	i++;
	// }
	
	return (0);
}
