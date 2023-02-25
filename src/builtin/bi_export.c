/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/25 06:28:19 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env/env.h"
#include "../../lib/the_lib/lib.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

static void puke_error(char *export_value)
{
	ft_putstr_fd("bash: export: `", 2);
	ft_putstr_fd(export_value, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

bool variable_name_allowed(char *str, char *export_value)
{
	int	j;
	bool misery;
	
	misery = false;
	if (str == NULL || ft_isdigit(str[0]) != 0)
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
	return(misery);
}

int bi_export(char **simple_command)
{
	char	**split;
	int		i;
	bool	misery;
	
	i = 1;
	while (simple_command[i] != NULL)
	{
		if (ft_strchr(simple_command[i], '=') != NULL)
		{
			split = ft_split(simple_command[i], '=');
			misery = variable_name_allowed(split[0], simple_command[i]);
			if (misery == false)
				add_env(ft_strdup(simple_command[i]));
			free_splits(split);
		}
		i++;
	}
	if (misery == true)
		return(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
