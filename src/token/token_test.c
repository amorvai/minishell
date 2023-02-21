/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:17:09 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/21 17:20:49 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(void)
{
	char	*line;
	t_token	*tokens;

	tokens = NULL;
	while (1)
	{
		line = readline("input: ");
		printf("return value:\t%i\n\n", init_tokens(&tokens, line));
		tokens_print(tokens);
		free(line);
	}
	return (0);
}

// hello " echo" ec"ho" | "echo "     " |echo " ls|  hi  |du
// hi|du  "ls"|  hi  |'d'u  'h'i|du  hi|d"u"
