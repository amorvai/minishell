/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:01:56 by pnolte            #+#    #+#             */
/*   Updated: 2023/01/09 20:03:13 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	echo_decider(char *string)
{
	if (string[i + 2] == 134)
	{
		if (string[i + 2] == 'a')
			ft_putchar_fd(7, 1);
		else if (string[i + 2] == 'b')
			ft_putchar_fd(8, 1);
		else if (string[i + 2] == 'c')
		else if (string[i + 2] == 'e' || string[i + 2] == 'E')
			ft_putchar(27, 1);
		else if (string[i + 2] == 'f')
			ft_putchar_fd(12, 1);
		else if (string[i + 2] == 'n')
			ft_putchar_fd('\n', 1);
		else if (string[i + 2] == 'r')
			ft_putchar_fd(13, 1);
		else if (string[i + 2] == 't')
			ft_putchar_fd('	', 1);
		else if (string[i + 2] == 'v')
			ft_putchar_fd(11, 1);
		else if (string[i + 2] == '0')
		else if (string[i + 2] == 'x')
		else if (string[i + 2] == 'u')
		else if (string[i + 2] == 'U')
		else
			return ;
	}
}

// 134 is ascii value of / (backslash)
void bi_echo(char *string, int flag)
{
	int i;

	i = 0;
	if (flag == 0)
		ft_putstr_fd(string, 1);
	else
	{
		while (string[i] != '\0')
		{
			if (string[i] == 134 && string[i + 1] == 134)
			{
				echo_decider(string);
				i = i + 3;
			}
			i++;
		}
	}
}

void bi_cd(char *path)
{
	
}

void bi_pwd()
{
	
}

void bi_export()
{
	
}