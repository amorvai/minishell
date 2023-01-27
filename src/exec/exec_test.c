/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:17:53 by pnolte            #+#    #+#             */
/*   Updated: 2023/01/27 17:16:40 by pnolte           ###   ########.fr       */
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
	t_simp_com *new;
	t_simp_com *new2;
	char *testcase[] = {"ls", NULL};
	char *testcase2[] = {"sort", NULL};
	char *testcase3[] = {"grep", "i", NULL};

	sc = malloc(sizeof(t_simp_com));
	new = malloc(sizeof(t_simp_com));
	new2 = malloc(sizeof(t_simp_com));
	new2->command = testcase3;
	new2->next = NULL;
	new->command = testcase2;
	new->next = new2;
	sc->command = testcase;
	sc->next = new;
	executer(sc);
	printf("%s\n", get_env("PWD"));
	// printf("FirstEntry:%s", head->content);
	// printf("SecondEntry:%s", head->next->content);
	
}