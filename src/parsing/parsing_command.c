/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 07:42:02 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/18 10:52:25 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h" // for is_redirection
#include "expansion.h"
#include "../token/token.h"
#include "../structure/command.h"
#include "../../lib/the_lib/lib.h" // ft_strdup

static int	command_word_count(t_token *it)
{
	int i;

	i = 0;
	while (it)
	{
		if (is_redirection(it->token))
			it = it->next;
		else
			i++;
		it = it->next;
	}
	return (i);
}

int	extract_command(t_token *it, t_simp_com *command)
{
	int i;

	command->command = malloc((command_word_count(it) + 1)* sizeof(char *));
	i = 0;
	while (it)
	{
		if (is_redirection(it->token))
			it = it->next;
		else
		{
			command->command[i] = expand_token(it->word);
			i++;
		}
		it = it->next;
	}
	command->command[i] = NULL;
	return (0);
}
