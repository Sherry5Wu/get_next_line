/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:10:08 by jingwu            #+#    #+#             */
/*   Updated: 2024/05/10 08:16:21 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/*
    Description:
    Write a function that returns a line read from a file descriptor.

    Parameters:
    fd: The file descriptor to read from.

    Return value:
    Read line: correct behavior.
    NULL: there is nothing else to read, or an error occurred.
*/

static char	*get_buffer(int fd, char *buffer)
{
	ssize_t	read_bytes;
	char	*tmp_buffer;

	tmp_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp_buffer)
		return (free_mem(&buffer));
	read_bytes = 1;
	while (!buffer || (buffer && !ft_strchr(buffer, '\n') && read_bytes > 0))
	{
		read_bytes = read(fd, tmp_buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(tmp_buffer);
			return (free_mem(buffer));
		}
		if (read_bytes == 0)
			break;
		tmp_buffer[read_bytes] = '\0';
		buffer = ft_strjoin(buffer, tmp_buffer);
	}
	free(tmp_buffer);
	// if (buffer[0] != '\0')
	// 	return (buffer);
	// return (NULL);
	return (buffer);
}

static char	*get_the_line(char *buffer)
{
	size_t  size;
	char	*line;

	size = 0;
	if (buffer)
	{
		while (buffer[size] && buffer[size] != '\n')
			size++;
	}
	line = (char *)malloc(sizeof(char) * (size + 2));
	if (!line)
		return (free_mem(&buffer));
	if (buffer[size] == '\n')
		line[size + 1] = '\0';
	while (size >= 0)
    {
		line[size] = buffer[size];
		size--;
    }
    return (line);
}

static char	*get_rest(char *buffer)
{
	char	*rest;
	int		i;

	i = 0;
	if (!buffer)
	{
		rest = NULL;
		return (free_mem(&buffer));
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free_mem(&buffer));
	rest = ft_substr(buffer, (i + 1), (ft_strlen(buffer) - (i + 1)));
	if (!rest)
		return (NULL);
	free_mem(&buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = get_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_the_line(buffer);
	if (!line)
		return (free_mem(&buffer));
	buffer = get_rest(buffer);
	return (line);
}