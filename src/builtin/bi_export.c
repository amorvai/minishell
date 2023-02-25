/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/02/25 17:38:13 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env/env.h"
#include "../error/error.h"
#include "../../lib/the_lib/lib.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

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
		print_export_unset(export_value, "export");
	return(misery);
}

void bi_export(char **simple_command)
{
	char	**split;
	int		i;
	bool	misery;
	
	i = 1;
	split = NULL;
	while (simple_command[i] != NULL)
	{
		if (ft_strchr(simple_command[i], '=') != NULL)
		{
			split = ft_split(simple_command[i], '=');
			misery = variable_name_allowed(split[0], simple_command[i]);
		}
		else
			misery = variable_name_allowed(simple_command[i], simple_command[i]);
		if (misery == false)
			add_env(ft_strdup(simple_command[i]));
		if (split != NULL)
			free_splits(split);
		i++;
	}
	if (misery != true)
		add_env(ft_xstrdup("?=0"));
}
