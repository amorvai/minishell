/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:17:53 by pnolte            #+#    #+#             */
/*   Updated: 2023/01/17 12:28:43 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int main()
{
	char *input[] = {"cd", "..", "\x19", "ls", "", "\x19", "echo", "-n", "\x19", "cat", ">", "tmp", "\x19", NULL};
	
	if (init_env() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	executer(input);
}