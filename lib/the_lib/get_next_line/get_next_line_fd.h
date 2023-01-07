/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_fd.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:47:09 by amorvai           #+#    #+#             */
/*   Updated: 2022/09/17 20:41:07 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_FD_H
# define GET_NEXT_LINE_FD_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
ssize_t	ft_strlen_mod(const char *s, int c);
void	*ft_memset(void *str, int c, size_t len);
char	*ft_substr_(const char *s, unsigned int start, ssize_t len);
char	*append_readline(char *buffer, char *readline);
char	*create_newline(char *buffer);
char	*buffer_restructure(char *buffer);

#endif