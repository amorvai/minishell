/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:44:12 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/21 17:09:18 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/the_lib/lib.h"

#include <signal.h>

static void signal_decider()
{
	
}

void signal_hand(int signo, siginfo_t *info)
{
	SIGQUIT
	SIGTSTP
	
}

struct sigaction init_sig()
{
	struct sigaction s_act;
	
	s_act.sa_flags = SA_SIGINFO;
	s_act.sa_sigaction = signal_hand;
	return(s_act);
}