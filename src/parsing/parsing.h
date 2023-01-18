/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:18:36 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/18 18:29:38 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../../inc/minishell.h"
# include "../token/token.h"
# include <stdbool.h>

typedef struct s_redirection
{
	enum e_token	redir_type;
	char			*file;
}				t_redirection;

typedef struct s_simp_command
{
	char					**command;
	t_redirection			*redirect_input;
	t_redirection			*redirect_output;
	struct s_simp_commands	*previous;
	struct s_simp_commands	*next;
}				t_simp_com;

// typedef struct s_command_line
// {
// 	t_simp_com	*simple_command;
	
// }				t_com_line;

#endif
