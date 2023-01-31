/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:18:36 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/31 17:49:11 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../../inc/minishell.h"
# include "../token/token.h"
# include <stdbool.h>

typedef struct s_redirection
{
	enum e_token			redir_type;
	char					*file;
	struct s_redirection	*next;
}				t_redirection;

typedef struct s_simp_command
{
	char					**command;
	t_redirection			*redirect_input;
	t_redirection			*redirect_output;
	struct s_simp_commands	*prev;
	struct s_simp_commands	*next;
}				t_simp_com;

// typedef struct s_command_line
// {
// 	t_simp_com	*simple_command;
	
// }				t_com_line;


void	command_add_back(t_simp_com **lst, t_simp_com *new_elem);
void	command_clear(t_simp_com **lst);

#endif
