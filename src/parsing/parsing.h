/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:18:36 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/27 15:37:03 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../minishell/minishell.h"
# include "../token/token.h"
# include "stdbool.h"

typedef struct s_redirection
{
	enum e_token	redir_type;
	char			*file;
}				t_redirection;

typedef struct s_simp_com
{
	char					**command;
	t_redirection			*redirect_input;
	t_redirection			*redirect_output;
	struct s_simp_com		*previous;
	struct s_simp_com		*next;
}				t_simp_com;

#endif
