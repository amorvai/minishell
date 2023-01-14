/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:02:07 by pnolte            #+#    #+#             */
/*   Updated: 2023/01/14 19:18:50 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../env/env.h"

int bi_export(char *value)
{
	char **split;
	
	if (ft_strchr(value, '=') == NULL)
		return (EXIT_FAILURE);
	split = ft_split(value, "=");
	add_env(split[0], split[1]);
	free(split);
	return (EXIT_SUCCESS);
}