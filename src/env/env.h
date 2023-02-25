/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:30:43 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/25 11:08:06 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

int		init_env(void);
void	free_env(void);

int		add_env(char *new_env); // export
int		del_env(char *key); // unset
void	print_env(void); // env

char	*get_env(char *key);

#endif
