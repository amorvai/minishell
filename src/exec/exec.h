/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:27:00 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/25 16:15:52 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../structure/command.h"
#include <signal.h>

void	executer(t_simp_com *cmds);
int		redirector(t_simp_com *single_cmd);
void	decisionmaker(char **simple_cmd);
void	multiple_pipes(t_simp_com *head, int amo_pipes);
void	idle_mode(int amo_cmd);

#endif
