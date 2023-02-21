/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 08:27:14 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/21 17:38:35 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../token/token.h"
#include "../env/env.h"
#include "../../lib/the_lib/lib.h"

char	*append_str(char *command_str,
					const char *str, size_t start, size_t len)
{
	char		*new_command_str;
	const char	*append;
	size_t		len_old;

	append = str + start;
	if (command_str)
		len_old = ft_strlen(command_str);
	else
		len_old = 0;
	new_command_str = ft_xcalloc(len_old + len + 1, sizeof(char));
	ft_memcpy(new_command_str, command_str, len_old);
	ft_strlcat(new_command_str, append, len_old + len + 1);
	if (command_str)
		free(command_str);
	return (new_command_str);
}

void	print_syntax_error(const t_token *nearby_token)
{
	add_env(ft_strdup("?=2"));
	ft_putstr_fd("miesmushell: syntax error near unexpected token ", 2);
	if (!nearby_token)
		ft_putstr_fd("\'newline\'\n", 2);
	else if (nearby_token->token == PIPE)
		ft_putstr_fd("\'|\'\n", 2);
	else if (nearby_token->token == GREAT)
		ft_putstr_fd("\'>\'\n", 2);
	else if (nearby_token->token == GGREAT)
		ft_putstr_fd("\'>>\'\n", 2);
	else if (nearby_token->token == LESS)
		ft_putstr_fd("\'<\'\n", 2);
	else if (nearby_token->token == LLESS)
		ft_putstr_fd("\'<<\'\n", 2);
}
