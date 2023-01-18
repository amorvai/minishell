/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:17:09 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/16 21:47:45 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main()
{
	char	*line;
	t_token	*tokens;

	tokens = NULL;
	// while (1)
	// {

	line = readline("tokens to count: ");
	printf("return value:\t%i\n\n", init_tokens(&tokens, line));
	tokens_print(tokens);
	// }
	return (0);
}

// hello " echo" ec"ho" | "echo "     " |echo " ls|  hi  |du  hi|du  "ls"|  hi  |'d'u  'h'i|du  hi|d"u"
