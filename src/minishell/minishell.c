/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:04:59 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/16 22:10:29 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../env/env.h"
#include "../token/token.h"

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

int	get_user_input()
{
	char	*read_line;

	read_line = readline("miesmushell is listening 🐚\n>>");
	add_history(read_line);
	return (read_line);
}

int	minishell()
{
	char	*read_line;
	t_token	*tokens;

	init_env();
	read_line = get_user_input();
	if (tokens_init(tokens, read_line))
		return (1); //there can only be quoting errors
	// if (read_line)d
	free_env();
	return (0);
}
