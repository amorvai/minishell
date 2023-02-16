/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:27:00 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/16 10:37:37 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../structure/command.h"

void	executer(t_simp_com *head);
void	where_ma_redirec(t_simp_com *cmds);
void	decisionmaker(char **simple_cmd, char *flex);
void	multiple_pipes(t_simp_com *head, int amo_pipes);
void	idle_mode(int amo_pipe);

#endif
