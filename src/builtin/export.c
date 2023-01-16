/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/01/16 14:45:30 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../env/env.h"

int bi_export(char *value)
{
	char **split;
	
	if (ft_strchr(value, '=') == NULL)
		return (EXIT_FAILURE);
	split = ft_split(value, '=');
	if (split[1] == NULL)
		add_env(split[0], "");
	add_env(split[0], split[1]);
	free(split);
	return (EXIT_SUCCESS);
}