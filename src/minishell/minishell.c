/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:04:59 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/23 21:03:58 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../env/env.h"
#include "../token/token.h"
#include "../parsing/parsing.h"
#include "../exec/exec.h"
#include "../../lib/the_lib/lib.h"

# include <stdio.h>
#include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

char	*get_user_input()
{
	char	*read_line;

	if (!isatty(0))
		return (get_next_line(0));
	printf("miesmushell is listening from %s", get_env("PWD"));
	read_line = readline("\n🐚... ");
	add_history(read_line);
	return (read_line);
}

int	minishell()
{
	char		*read_line;
	t_token		*tokens;
	t_simp_com	*commands;

	init_env();
	add_env(ft_strdup("?=0"));
	while (1)
	{
		read_line = get_user_input();
		if (!read_line)
			break ;
		tokens = NULL;
		commands = NULL;
		if (token_lst_init(&tokens, read_line) || !tokens || parse(&tokens, &commands))
			continue ;
		// print_command_lst(commands);
		// heredoc(commands);
		executer(commands);
		command_lst_clear(&commands);
	}
	free_env();
	// printf("pid %i\n", getpid());
	// while(1)
	// 	;
	return (1);
}
