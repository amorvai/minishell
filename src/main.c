/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:27:55 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/07 06:56:18 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// int	main(int argc, char **argv, char **envp)
// {
// 	char	*line;


// 	line = readline("say something: ");
// 	// ft_printf("%s\n", line);
	
// }

int	main(int argc, char **argv, char **envp)
{
	t_command	command_string;

	(void)argc;
	(void)argv;
	(void)envp;

	command_string = (t_command){0};
	if (parsing(&command_string))
		return (1);
	// print_overview(command_string);
}
