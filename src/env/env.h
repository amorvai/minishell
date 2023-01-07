/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:30:43 by amorvai           #+#    #+#             */
/*   Updated: 2023/01/07 17:57:15 by amorvai          ###   ########.fr       */
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

int		add_env(char *key, char *value);
int		del_env(char *key);
void	print_env(void);

char	*get_env(char *key);

#endif
