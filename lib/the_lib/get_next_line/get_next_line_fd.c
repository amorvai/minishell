/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:47:16 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/25 10:29:52 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_fd.h"
#include "../libft/libft.h" // ft_memset
#include <unistd.h>

int	get_next_line(int fd, char **newline)
{
	static char		*buffer[10240];
	char			readline[BUFFER_SIZE + 1];
	int				rvalue;

	rvalue = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	while (ft_strlen_mod(buffer[fd], '\n') <= 0 && rvalue > 0)
	{
		ft_memset(readline, '\0', BUFFER_SIZE + 1);
		rvalue = read(fd, readline, BUFFER_SIZE);
		if (rvalue == -1)
			return (-1);
		buffer[fd] = append_readline(buffer[fd], readline);
	}
	if (buffer[fd])
	{
		*newline = create_newline(buffer[fd]);
		buffer[fd] = buffer_restructure(buffer[fd]);
	}
	return (0);
}
