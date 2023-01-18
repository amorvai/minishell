/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:17:09 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/16 21:19:20 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>

int main()
{
	char	*line;
	int		nb_token;
	t_token	*tokens;

	while (1)
	{

	line = readline("tokens to count: >");
	nb_token = 0;
	// printf("line : [%s]\n", line);
	// printf("no_of_tokens(hello \" echo\" ec\"ho\" \"echo \"     \" echo \" what up boys i" " certainly \"agree\")\nreturn value: %i\n# of tokens: %i\n",\
	// 		 no_of_tokens("hello \" echo\" ec\"ho\" \"echo \"     \" echo \" what up boys i" " certainly \"agree\"", &token), token);
	printf("\nno_of_tokens(%s)\nreturn value: %i\n# of tokens: %i\n\n\n", \
			line, no_of_tokens(line, &nb_token, tokens), nb_token);
	}
	return (0);
}

// hello " echo" ec"ho" | "echo "     " |echo " ls|  hi  |du  hi|du  "ls"|  hi  |'d'u  'h'i|du  hi|d"u"
