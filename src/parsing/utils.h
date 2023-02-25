/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 08:28:52 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/24 17:39:21 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../token/token.h"
# include <stdio.h> // or stdlib.h?

char	*expand_env_var(char *command_str, const char *str, size_t *i);
char	*expand_sing_quote(char *command_str, const char *str, size_t *i);
char	*expand_doub_quote_simple(char *command_str,
			const char *str, size_t *i);

char	*append_str(char *command_str,
			const char *str, size_t start, size_t len);

#endif
