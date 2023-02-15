/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:30:43 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/15 15:12:29 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct s_env
{
	char	*key;
	char	*value;
}				t_env;

int		init_env(void);
void	free_env(void);

int		add_env(char *key, char *value); // export
int		del_env(char *key); // unset
void	print_env(char *flex); // env

char	*get_env(char *key);

#endif
