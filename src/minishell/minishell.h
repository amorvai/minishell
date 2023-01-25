/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:05:14 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/24 14:42:04 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// typedef struct s_simple_command
// {
// 	int	no_avail_args;
// 	int	no_args;
// 	char **arguments;
	
// }				t_simple_command;

// typedef struct s_command
// {
// 	int						no_avail_commands;
// 	int						no_commands;
// 	t_simple_command		**simple_commands;
// 	char					*outfile;
// 	char					*infile;
// 	char					*errfile;
// 	int						background;
// 	/* static */ t_simple_command	*current_s_command;
// }				t_command;

int	minishell();

#endif
