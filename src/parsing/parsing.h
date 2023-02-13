/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:18:36 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/13 10:52:48 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../minishell/minishell.h"
# include "../token/token.h"
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
	struct s_simp_command	*prev;
	struct s_simp_command	*next;
}				t_simp_com;

t_redirection	*extract_redirection(t_token *temp_lst);
void			redir_add_back(t_redirection **lst, t_redirection *new_elem);
void			print_redirection(t_redirection *redirection);

void			command_add_back(t_simp_com **lst, t_simp_com *new_elem);
void			command_clear(t_simp_com **lst);
void			print_commands(t_simp_com *command);

char			*expand_token(char *str);

void			append_str(char **command_str, char *str, size_t start, size_t len);
t_simp_com		*parse_for_commands(t_token **token_lst);



#endif
