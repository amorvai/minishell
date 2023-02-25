/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:55:16 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/24 17:38:27 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "../token/token.h"

void	print_syntax_error(const t_token *nearby_token);

int		print_permission_denied(char *file);
int		print_is_directory(char *file);
int		print_command_not_found(char *file);
int 	print_no_such(char *file, char *flex);
int		print_redirection_protection();
int 	print_fork_protection();

#endif
