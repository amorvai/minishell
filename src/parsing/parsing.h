/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:18:36 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/16 10:29:37 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../token/token.h"
# include "../structure/command.h"
# include <stdio.h> // included in token.h

char			*expand_token(char *str);

void			append_str(char **command_str, char *str, size_t start, size_t len);
t_simp_com		*parse_for_commands(t_token **token_lst);

#endif
