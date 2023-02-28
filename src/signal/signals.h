/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:43:42 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/28 14:05:46 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

#include <stdio.h>
#include <signal.h>
#include <readline/readline.h>

void	terminal_switcher(char *flex);
void	destroy_heredoc(int signum, siginfo_t *info, void *context);
void	sig_hand(int signum);
void	redisplay_the_muschel(int signum);
void	rl_replace_line (const char *text, int clear_undo);
int		get_signals_return_value(int signum);

#endif
