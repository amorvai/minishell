/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:00:04 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/11 13:16:58 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int parsing(t_command *command_string)
{
	char	*line;
	char	**splits;
	char	**tokens;

	line = readline("say something: ");
	// ft_printf("%s\n", line);
	splits = ft_split(line, ' ');
	if (splits == NULL)
		return (3);
	if (create_list(splits, command_string))
		return (4);
	return (0);
}

int create_list(char **splits, t_command *command_string)
{
	int	i;

	i = 0;
	while (splits[i] != NULL)
	{
		break ;
	}
	return (0);
}
