/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/28 20:08:37 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env/env.h"
#include "../../lib/the_lib/lib.h"

#include <unistd.h>
#include <stdbool.h>

static void	puke_error(char *export_value)
{
	add_env(ft_xstrdup("?=1"));
	ft_putstr_fd("miesmushell: unset: `", 2);
	ft_putstr_fd(export_value, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

static bool	variable_name_allowed(char *str, char *export_value)
{
	int		j;
	bool	misery;

	misery = false;
	if (str == NULL || ft_isdigit(str[0]) != 0 || str[0] == '\0')
		misery = true;
	j = 0;
	while (misery == false && str[j] != '\0')
	{
		misery = true;
		if (ft_isalnum(str[j]) == true || str[j] == '_')
			misery = false;
		j++;
	}
	if (misery == true)
		puke_error(export_value);
	else
		add_env(ft_xstrdup("?=0"));
	return (misery);
}

void	bi_unset(char **cmds)
{
	int		i;

	i = 1;
	while (cmds[i] != NULL)
	{
		if (variable_name_allowed(cmds[i], cmds[i]))
			return ;
		if (del_env(cmds[i]))
			add_env(ft_xstrdup("?=1"));
		i++;
	}
}
