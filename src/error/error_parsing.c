/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:36:01 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/24 17:39:08 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../token/token.h"
#include "../env/env.h"
#include "../../lib/the_lib/lib.h"

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
