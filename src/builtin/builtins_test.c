/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:33:45 by pnolte            #+#    #+#             */
/*   Updated: 2023/01/16 17:42:52 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../env/env.h"

// int cd_test()
// {
// 	char *testcase[] = {NULL, "/", "~", "/Users/pnolte/projects/private_git/minishell/inc", "..", "src/exec", "fail", 
// 						"/Users/pnolte/projects/private_git/minishell/inc/fail", "/Users/pnolte/projects/private_git/minishell/inc/fail.c",
// 						"fail.c", NULL};
// 	char *output[] =  {"/Users/pnolte", "/", "/Users/pnolte", "/Users/pnolte/projects/private_git/minishell/inc",
// 						"/Users/pnolte/projects/private_git/minishell", "/Users/pnolte/projects/private_git/minishell/src/exec",
// 						"/Users/pnolte/projects/private_git/minishell/src/exec", "/Users/pnolte/projects/private_git/minishell/src/exec", 
// 						"/Users/pnolte/projects/private_git/minishell/src/exec", "/Users/pnolte/projects/private_git/minishell/src/exec", NULL};
// 	int i = 0;
	
// 	while (i < 9)
// 	{
// 		bi_cd(testcase[i]);
// 		if (ft_strcmp(get_env("PWD"), output[i]) != 0 )
// 		{
// 			printf("ERROR%i=========\n%s\n%s\nERROR%i=======\n\n",i, get_env("PWD"), output[i], i);
// 		}
// 		printf("%s\n\n", get_env("PWD"));
// 		i++;
// 	}
// 	return (EXIT_SUCCESS);	
// }

int export_unset_test()
{
	char *testcases[] = {"new=", "new=filled", "new=different", "new", "fcxhjkvdksfxklkj", NULL};
	char *output[] = {"", "filled", "different", "", "", NULL};
	int i = 0;
	
	while (i < 5)
	{
		if (i == 3 || i == 4)
			bi_unset(testcases[i]);
		else
			bi_export(testcases[i]);
		if (ft_strcmp(get_env("new"), output[i]) != 0)
		{
			printf("ERROR%i=========\n%s\n%s\nERROR%i=======\n\n",i, get_env("new"), output[i], i);
		}
		printf("%s\n\n", get_env("new"));
		i++;
	} 
	return (EXIT_SUCCESS);
}

int main()
{
	if (init_env() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	// if (cd_test() == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);
	if (export_unset_test() == EXIT_FAILURE)
		return(EXIT_FAILURE);
	system("leaks a.out");
	return (EXIT_SUCCESS);
}