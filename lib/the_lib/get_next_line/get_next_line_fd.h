/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_fd.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:47:09 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/25 10:30:56 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_FD_H
# define GET_NEXT_LINE_FD_H

# include <unistd.h> // ssize_t

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		get_next_line(int fd, char **newline);

ssize_t	ft_strlen_mod(const char *s, int c);
char	*append_readline(char *buffer, char *readline);
char	*create_newline(char *buffer);
char	*buffer_restructure(char *buffer);

#endif
