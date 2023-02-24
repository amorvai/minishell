/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:44:12 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/24 16:48:50 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/the_lib/lib.h"

#include <signal.h>

void signal_decider(struct sigaction s_act)
{
	(void)s_act;
}

void signal_hand(int signo, siginfo_t *info, void *context)
{
	(void)signo;
	(void)info;
	(void)context;
}

struct sigaction init_sig()
{
	struct sigaction s_act;
	
	s_act.sa_flags = SA_SIGINFO;
	s_act.sa_sigaction = signal_hand;
	return(s_act);
}