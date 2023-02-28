/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:27:00 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/28 12:05:27 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../structure/command.h"
# include <sys/types.h>

// exec_pipes

void	multiple_pipes(t_simp_com **cmds, int amo_pipes);

// exec_rede

int		redirector(t_simp_com **single_cmd);

// exec_utils

int		is_builtin(char *cmd);
void	execute_builtin(t_simp_com **c);
int		check_validity(char *filename, char *path);
char	*get_executable_path(char *arg_one);

// exec

void 	idle_mode(int amo_cmd, pid_t pids[amo_cmd]);
void	executer(t_simp_com **cmds);

#endif
