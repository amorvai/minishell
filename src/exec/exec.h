/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:27:00 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/25 10:51:18 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../structure/command.h"
#include <signal.h>

void	executer(t_simp_com *head);
int		where_ma_redirec(t_simp_com *single_cmd);
void	decisionmaker(char **simple_cmd, char *flex);
int		multiple_pipes(t_simp_com *head, int amo_pipes);
int		idle_mode(int amo_pipe);

#endif
