/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 00:33:27 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/18 09:43:36 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include <stdio.h>
// #include "whateverthefuck"

enum e_token {
	WORD,
	PIPE,
	GREAT,
	LESS,
	GGREAT,
	LLESS
} ;

typedef struct s_token
{
	enum e_token	token;
	char			*word;
	struct s_token	*prev;
	struct s_token	*next;
}				t_token;

// t_token	*tokenlast(t_token *lst);

void	token_lst_add_back(t_token **lst, t_token *new_token);
void	token_delete(t_token **lst, t_token *tobedeleted);
void	token_lst_clear(t_token **lst);
void	free_token_lst_array(t_token **token_lst_array, int array_len);
void	token_lst_print(t_token *token_lst);

int		token_lst_init(t_token **token_lst, const char *s);

#endif
