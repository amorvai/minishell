/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:17:53 by pnolte            #+#    #+#             */
/*   Updated: 2023/01/25 17:05:02 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "stdio.h"
#include "../parsing/parsing.h"
#include "../../lib/the_lib/libft/libft.h"
#include "../env/env.h"

int main()
{
	t_simp_com *sc;
	char *testcase[] = {"cd", "minishell", NULL};

	sc = malloc(sizeof(t_simp_com));
	sc->command = testcase;
	executer(sc);
	printf("%s\n", get_env("PWD"));
	// printf("FirstEntry:%s", head->content);
	// printf("SecondEntry:%s", head->next->content);
	
}