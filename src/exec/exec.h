/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:27:00 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/14 17:02:36 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../parsing/parsing.h" 

void	executer(t_simp_com *head);
int		command_and_counter(t_simp_com *head);
void	where_ma_redirec(t_simp_com *cmds);
void	decisionmaker(char **simple_cmd, char *flex);
void multiple_pipes(t_simp_com *head, int amo_pipes);
void	idle_mode(int amo_pipe);

#endif