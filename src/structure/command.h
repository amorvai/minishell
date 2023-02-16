/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:05:00 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/16 10:33:25 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "redirection.h"

typedef struct s_simp_command
{
	char					**command;
	t_redirection			*redirect_input;
	t_redirection			*redirect_output;
	struct s_simp_command	*prev;
	struct s_simp_command	*next;
}				t_simp_com;


void	free_str_arr(char **str); //doesnt belong there


int				command_lst_len(t_simp_com *head);
void			command_lst_add_back(t_simp_com **lst, t_simp_com *new_elem);
void			command_lst_clear(t_simp_com **lst);
void			print_command_lst(t_simp_com *command);

#endif
