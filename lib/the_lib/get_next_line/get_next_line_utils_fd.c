/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:01:05 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/23 11:50:56 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // free
#include <unistd.h> // ssize_t
#include "../libft/libft.h" // ft_calloc

ssize_t	ft_strlen_mod(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	if (c == '\0')
		return (i);
	return (-1);
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

static char	*ft_substr_mod(const char *s, unsigned int start, ssize_t len)
{
	char	*substr;
	ssize_t	i;

	if (s == NULL)
		return (NULL);
	substr = malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (len > i && (ssize_t)start < ft_strlen_mod(s, '\0'))
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
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
		nextline = ft_substr_mod(buffer, (unsigned int) i, j - i);
	free(buffer);
	buffer = NULL;
	if ((j - i) > 0)
	{
		buffer = ft_substr_mod(nextline, 0, j - i);
		free(nextline);
	}
	return (buffer);
}
