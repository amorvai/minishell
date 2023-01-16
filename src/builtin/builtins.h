/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:58:59 by pnolte            #+#    #+#             */
/*   Updated: 2023/01/16 14:20:54 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../../inc/minishell.h"

void	bi_echo(char *string, int flag);
void	bi_cd(char *path);
void	bi_pwd();
void	bi_exit();
void	bi_unset();
int		bi_env(char *value);
int		bi_export(char *value);

#endif
