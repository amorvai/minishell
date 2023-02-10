/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:17:53 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/10 17:21:04 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdio.h>
#include <unistd.h>
#include "../parsing/parsing.h"
#include "../../lib/the_lib/libft/libft.h"
#include "../env/env.h"
#

int main()
{
	t_simp_com *sc;
	t_simp_com *new;
	t_simp_com *new2;
	t_simp_com *new3;
	char *testcase[] = {"env", NULL};
	char *testcase2[] = {"sort", NULL};
	char *testcase3[] = {"", NULL};
	char *testcase4[] = {"grep", "e", NULL};

	sc = malloc(sizeof(t_simp_com));
	new = malloc(sizeof(t_simp_com));
	new2 = malloc(sizeof(t_simp_com));
	new3 = malloc(sizeof(t_simp_com));
	new3->command = testcase4;
	new3->next = NULL;
	new2->command = testcase3;
	new2->next = NULL;
	new->command = testcase2;
	new->next = NULL;
	sc->command = testcase;
	sc->next = new;
	executer(sc);
	// printf("hey\n");
	// sleep(1000);
	// printf("%s\n", get_env("PWD"));
	// printf("FirstEntry:%s", head->content);
	// printf("SecondEntry:%s", head->next->content);
	
}