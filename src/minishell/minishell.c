/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:04:59 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/25 14:40:58 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../env/env.h"
#include "../token/token.h"
#include "../parsing/parsing.h"
#include "../exec/exec.h"
#include "../signal/signals.h"
#include "../../lib/the_lib/lib.h"

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

char	*get_user_input()
{
	char	*read_line;

	read_line = NULL;
	if (!isatty(0))
	{
		get_next_line(0, &read_line);
		return (read_line);
	}
	printf("miesmushell is listening from %s", get_env("PWD"));
	read_line = readline("\n🐚... ");
	add_history(read_line);
	return (read_line);
}

int	minishell(void)
{
	char		*read_line;
	t_token		*tokens;
	t_simp_com	*commands;
	int			exit_code = 0;
	
	init_env();
	signal(SIGQUIT, SIG_IGN);
	add_env(ft_strdup("?=0"));
	while (1)
	{
		signal(SIGINT, redisplay_the_muschel);
		terminal_switcher("input");
		read_line = get_user_input();
		if (!read_line)
			break ;
		tokens = NULL;
		commands = NULL;
		if (token_lst_init(&tokens, read_line) || !tokens
			|| parse(&tokens, &commands))
			continue ;
		// print_command_lst(commands);
		executer(commands);
		command_lst_clear(&commands);
	}
	if (isatty(STDERR_FILENO) != 0)
		ft_putstr_fd("exit\n", STDERR_FILENO);
	clear_history();
	// printf("pid %i\n", getpid());
	// while(1)
	free_env();
	return (exit_code);
}
