/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:58:59 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/28 14:20:55 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdbool.h>
# include "../structure/command.h"

char	*grab_cwd(void);

void	bi_echo(char **simple_command);
int		bi_cd(char *path);
int		bi_pwd(void);
void	bi_exit(t_simp_com **c);
void	bi_unset(void);
int		bi_env(char **simple_command);
int		bi_export(char **simple_command);

bool	variable_name_allowed(char *str, char *export_value);

#endif
