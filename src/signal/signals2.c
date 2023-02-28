/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:10:00 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/28 19:44:38 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/the_lib/lib.h"
#include "signals.h"

void	signal_activate(char *flex)
{
	if (ft_strcmp(flex, "interactive") == 0)
	{
		signal(SIGINT, redisplay_the_muschel);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (ft_strcmp(flex, "execute") == 0)
	{
		signal(SIGINT, sig_hand);
		signal(SIGQUIT, sig_hand);
	}
}

void	signal_deactivater(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	sigact_heredoc(void)
{
	struct sigaction	s_act;

	s_act.sa_flags = 0;
	sigemptyset(&s_act.sa_mask);
	s_act.sa_sigaction = destroy_heredoc;
	sigaction(SIGINT, &s_act, NULL);
}
