/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:17:53 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/16 12:42:19 by pnolte           ###   ########.fr       */
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
	t_redirection *input1;
	t_redirection *input2;
	t_redirection *input3;
	t_redirection *output1;
	t_redirection *output2;
	t_redirection *output3;
	char *testcase[] = {"cat", "-e", NULL};
	char *testcase2[] = {"cat", "-e", NULL};
	char *testcase3[] = {"", NULL};
	char *testcase4[] = {"sort", NULL};
	char i_f1[] = "infile1";
	char i_f2[] = "infile2";
	char i_f3[] = "infile3";
	char o_f1[] = "outfile1";
	char o_f2[] = "outfile2";
	char o_f3[] = "outfile3";

	sc = malloc(sizeof(t_simp_com));
	new = malloc(sizeof(t_simp_com));
	new2 = malloc(sizeof(t_simp_com));
	new3 = malloc(sizeof(t_simp_com));
	input1 = malloc(sizeof(t_redirection));
	input2 = malloc(sizeof(t_redirection));
	input3 = malloc(sizeof(t_redirection));
	output1 = malloc(sizeof(t_redirection));
	output2 = malloc(sizeof(t_redirection));
	output3 = malloc(sizeof(t_redirection));
	sc->next = new;
	new->next = new3;
	new2->next = NULL;
	new3->next = NULL;
	sc->command = testcase;
	new2->command = testcase3;
	new3->command = testcase4;
	new->command = testcase2;
	sc->redirect_input = input1;
	sc->redirect_output = output1;
	new->redirect_input = input3;
	new->redirect_output = output3;
	new3->redirect_input = NULL;
	new3->redirect_output = NULL;
	output1->file = o_f1;
	output2->file = o_f2;
	output3->file = o_f3;
	input1->file = i_f1;
	input2->file = i_f2;
	input3->file = i_f3;
	input1->redir_type = LESS;
	input2->redir_type = LESS;
	input3->redir_type = LESS;
	output1->redir_type = GREAT;
	output2->redir_type = GREAT;
	output3->redir_type = GREAT;
	input1->next = NULL;
	input2->next = input3;
	input3->next = NULL;
	output1->next = NULL;
	output2->next = output3;
	output3->next = NULL;
	executer(sc);
	// printf("hey\n");
	// sleep(1000);
	// printf("%s\n", get_env("PWD"));
	// printf("FirstEntry:%s", head->content);
	// printf("SecondEntry:%s", head->next->content);
	
}