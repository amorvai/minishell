/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:55:16 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/27 15:54:41 by pnolte           ###   ########.fr       */
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
int		print_open_protection();
void	print_export_unset(char *value, char *flex);

#endif
