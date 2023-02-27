/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:55:22 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/27 19:18:28 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/the_lib/lib.h"
#include "../env/env.h"

#include <unistd.h>

void	print_command_not_found(char *file)
{
	add_env(ft_strdup("?=127"));
	ft_putstr_fd("miesmushell: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": command not found\n", 2);
}

void	print_permission_denied(char *file)
{
	add_env(ft_strdup("?=1"));
	ft_putstr_fd("miesmushell: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": Permission denied\n", 2);
}

void	print_no_such(char *file, char *flex)
{
	add_env(ft_strdup("?=1"));
	ft_putstr_fd("miesmushell: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": No such", 2);
	if (ft_strcmp("file", flex) == 0)
		ft_putstr_fd(" file\n", 2);
	else if (ft_strcmp("directory", flex) == 0)
		ft_putstr_fd(" directory\n", 2);
	else if (ft_strcmp("file_or_dire", flex) == 0)
		ft_putstr_fd(" file or directory\n", 2);
}

void	print_is_directory(char *file)
{
	add_env(ft_strdup("?=126"));
	ft_putstr_fd("miesmushell: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": Is a directory\n", 2);
}

void	print_export_unset(char *value, char *flex)
{
	if (ft_strcmp(flex, "export") == 0)
		ft_putstr_fd("miesmushell: export: `", 2);
	else if (ft_strcmp(flex, "unset") == 0)
		ft_putstr_fd("miesmushell: unset: `", 2);	
	ft_putstr_fd(value, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}