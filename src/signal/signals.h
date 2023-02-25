/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:43:42 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/25 03:35:16 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

#include <stdio.h>
#include <signal.h>
#include <readline/readline.h>

void	terminal_switcher(char *flex);
void	sig_hand(int signum);
void	redisplay_the_muschel(int signum);
void	rl_replace_line (const char *text, int clear_undo);

#endif
