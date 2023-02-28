/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:58:59 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/28 10:44:15 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdbool.h>
# include "../structure/command.h"

char	*grab_cwd();

void	bi_echo(char **simple_command);
int		bi_cd(char *path);
int		bi_pwd();
void	bi_exit(t_simp_com **c);
void	bi_unset();
int		bi_env(char **simple_command);
int		bi_export(char **simple_command);

#endif
