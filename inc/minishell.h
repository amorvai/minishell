/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:18:15 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/11 15:01:44 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/the_lib/lib.h"
# include <stdbool.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

// typedef struct s_minishell
// {
//     /* data */
// }               t_minishell;

// typedef struct s_token
// {
//     char *read;

// }               t_token;

// typedef struct s_minishell
// {
// 	/* data */
// }				t_minishell;

typedef struct s_simple_command
{
	int	no_avail_args;
	int	no_args;
	char **arguments;
	
}				t_simple_command;

typedef struct s_command
{
	int						no_avail_commands;
	int						no_commands;
	t_simple_command		**simple_commands;
	char					*outfile;
	char					*infile;
	char					*errfile;
	int						background;
	/* static */ t_simple_command	*current_s_command;
}				t_command;

int create_list(char **splits, t_command *command_string);

#endif
