/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 08:28:52 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/18 10:00:44 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../token/token.h"
# include <stdio.h> // or stdlib.h?

void	append_str(char **command_str, char *str, size_t start, size_t len);
void	print_syntax_error(const t_token *nearby_token);

#endif