/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:44:12 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/25 15:39:40 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/the_lib/lib.h"
#include "../builtin/builtins.h"
#include "../env/env.h"
#include "signals.h"

#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <unistd.h>
#include <termios.h>
#include <sys/stat.h>

void destroy_heredoc(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	
	if (signum == SIGINT)
	{
		ft_putchar_fd('\0', STDIN_FILENO);
		ft_putchar_fd('\n', 2);
		add_env(ft_strdup("42heredoc=quit"));
		add_env(ft_strdup("?=1"));
	}
}

void redisplay_the_muschel(int signum)
{
	if (signum == SIGINT)
	{
		write(STDERR_FILENO, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		add_env(ft_strdup("?=1"));
	}
}

void	sig_hand(int signum)
{
	if (signum == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		add_env(ft_strdup("?=130"));
	}
	else if (signum == SIGQUIT)
	{
		ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
		add_env(ft_strdup("?=131"));
	}
}

void terminal_switcher(char *flex)
{
	struct termios termios;
	
	if (ft_strcmp(flex, "input") == 0)
	{
		tcgetattr(STDOUT_FILENO, &termios);
		termios.c_lflag &= ~ECHOCTL;
		tcsetattr(STDOUT_FILENO, TCSANOW, &termios);
	}
	else if (ft_strcmp(flex, "execute") == 0)
	{
		tcgetattr(STDOUT_FILENO, &termios);
		termios.c_lflag |= ECHOCTL;
		tcsetattr(STDOUT_FILENO, TCSANOW, &termios);
	}
}

//tcsanow = make changes immediatley
