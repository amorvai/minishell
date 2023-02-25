/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:18:36 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/24 17:58:42 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../token/token.h"
# include "../structure/command.h"

int	parse(t_token **token_lst, t_simp_com **head_command);

int	is_redirection(enum e_token token_type);
int	extract_redirections(t_token *it, t_token *next_lst, t_simp_com *command);

int	extract_command(t_token *it, t_simp_com *command);

#endif
