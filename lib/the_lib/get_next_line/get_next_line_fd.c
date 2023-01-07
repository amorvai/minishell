/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:47:16 by amorvai           #+#    #+#             */
/*   Updated: 2022/09/17 20:41:24 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_fd.h"

char	*get_next_line(int fd)
{
	static char		*buffer[10240];
	char			readline[BUFFER_SIZE + 1];
	char			*newline;
	int				rvalue;

	newline = NULL;
	rvalue = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ft_strlen_mod(buffer[fd], '\n') <= 0 && rvalue > 0)
	{
		ft_memset(readline, '\0', BUFFER_SIZE + 1);
		rvalue = read(fd, readline, BUFFER_SIZE);
		if (rvalue == -1)
			return (NULL);
		buffer[fd] = append_readline(buffer[fd], readline);
	}
	if (buffer[fd])
	{
		newline = create_newline(buffer[fd]);
		buffer[fd] = buffer_restructure(buffer[fd]);
		return (newline);
	}
	return (NULL);
}

char	*append_readline(char *buffer, char *readline)
{
	char	*temp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	temp = ft_calloc(ft_strlen_mod(buffer, '\0') \
	+ ft_strlen_mod(readline, '\0') + 1, sizeof(char));
	if (temp == NULL)
		return (NULL);
	while (buffer && buffer[i] != '\0')
	{
		temp[i] = buffer[i];
		i++;
	}
	while (readline && readline[j] != '\0')
	{
		temp[i + j] = readline[j];
		j++;
	}
	if (buffer)
		free(buffer);
	if (buffer)
		buffer = NULL;
	return (temp);
}

char	*create_newline(char *buffer)
{
	char	*newline;
	ssize_t	i;
	ssize_t	pos;

	pos = ft_strlen_mod(buffer, '\n');
	if (pos == -1)
		pos = ft_strlen_mod(buffer, '\0');
	newline = ft_calloc(pos + 1, sizeof(char));
	i = 0;
	while (i < pos && buffer[i] != '\0')
	{
		newline[i] = buffer[i];
		i++;
	}
	if (i == 0)
	{
		free(newline);
		newline = NULL;
	}
	return (newline);
}

char	*buffer_restructure(char *buffer)
{
	char	*nextline;
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = 0;
	nextline = NULL;
	i = ft_strlen_mod(buffer, '\n');
	if (i == -1)
	{
		free(buffer);
		buffer = NULL;
		return (buffer);
	}
	j = ft_strlen_mod(buffer, '\0');
	if ((j - i) > 0)
		nextline = ft_substr_(buffer, (unsigned int) i, j - i);
	free(buffer);
	buffer = NULL;
	if ((j - i) > 0)
	{
		buffer = ft_substr_(nextline, 0, j - i);
		free(nextline);
	}
	return (buffer);
}
