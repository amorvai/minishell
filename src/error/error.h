/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:55:16 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/24 16:25:20 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

int	print_permission_denied(char *file);
int	print_is_directory(char *file);
int	print_command_not_found(char *file);
int print_no_such(char *file, char *flex);
int	print_redirection_protection();
int print_fork_protection();

#endif
