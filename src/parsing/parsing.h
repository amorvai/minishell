/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:18:36 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/10 00:52:19 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../../inc/minishell.h"

int	no_of_tokens(const char *s, int *tokens);


int	parsing(t_command *command_string);

enum token {
	WORD, PIPE, GREAT, LESS, GGREAT, LLESS
}

typedef struct s_token
{
	enum token		token;
	char			*word;
	struct s_token	*next;
}				t_token;

#endif
