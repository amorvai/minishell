/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:15:28 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/21 15:09:24 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "../token/token.h"

typedef struct s_redirection
{
	enum e_token			redir_type;
	char					*file;
	int						fd;
	struct s_redirection	*next;
}				t_redirection;

void	redir_add_back(t_redirection **lst, t_redirection *new_elem);
void	free_redirection(t_redirection *redirections);
void	print_redirection(t_redirection *redirection);

#endif
