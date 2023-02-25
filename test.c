/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:57:48 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/25 00:09:43 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <stdio.h>
#include <unistd.h>

#define _POSIX_SOURCE
#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signal_hand(int signo, siginfo_t *info, void *context)
{
	(void)signo;
	(void)info;
	(void)context;
	if (signo == SIGQUIT)
		printf("SIGQUIT\n");
	if (signo == SIGINT)
		printf("SIGINT\n");
}


int main() {
	struct sigaction s_act;
	struct termios	t;
	
	s_act.sa_flags = SA_SIGINFO;
	s_act.sa_sigaction = signal_hand;
	tcgetattr(STDIN_FILENO, &t);
	t.c_lflag &= ~ECHOCTL;
	// t.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, 0, &t);
	while (1)
	{
		sigaction(SIGQUIT, &s_act, NULL);
		sigaction(SIGINT, &s_act, NULL);
	}	
}