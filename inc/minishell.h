/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:18:15 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/16 22:14:33 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/the_lib/lib.h"
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

int create_list(char **splits, t_command *command_string);

#endif
