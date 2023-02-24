/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:55:22 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/24 16:38:35 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/the_lib/lib.h"

#include <unistd.h>

int	print_command_not_found(char *file)
{
	ft_putstr_fd("🐚: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": command not found\n", 2);
	return(EXIT_FAILURE);
}

int	print_permission_denied(char *file)
{
	ft_putstr_fd("🐚: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	return(EXIT_FAILURE);
}

int print_no_such(char *file, char *flex)
{
	ft_putstr_fd("🐚: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": No such", 2);
	if (ft_strcmp("file", flex) == 0)
		ft_putstr_fd(" file\n", 2);
	if (ft_strcmp("directory", flex) == 0)
		ft_putstr_fd(" directory\n", 2);
	if (ft_strcmp("file_or_dire", flex) == 0)
		ft_putstr_fd(" file or directory\n", 2);
	return(EXIT_FAILURE);
}

int	print_is_directory(char *file)
{
	ft_putstr_fd("🐚: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": Is a directory\n", 2);
	return(EXIT_FAILURE);
}

int print_fork_protection()
{
	ft_putstr_fd("🐚: Fork creation failed ", 2);
	return(EXIT_FAILURE);
}

int print_redirection_protection()
{
	ft_putstr_fd("🐚: Redirection failed ", 2);
	return(EXIT_FAILURE);
}