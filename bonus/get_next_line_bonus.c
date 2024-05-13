/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:42:34 by jingwu            #+#    #+#             */
/*   Updated: 2024/05/10 14:18:31 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

static char	*get_buffer(int fd, char *buffer)
{
	char	*tmp_buffer;
	ssize_t	read_bytes;

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
			return (free_mem(&buffer));
		}
		if (read_bytes == 0)
			break;
		tmp_buffer[read_bytes] = '\0';
		buffer = ft_strjoin(buffer, tmp_buffer);
	}
	free(tmp_buffer);
	if (!buffer)
		return (NULL);
	return (buffer);
}

static char	*get_the_line(char *buffer)
{
	ssize_t	size;
	char	*line;

	size = 0;
	while (buffer[size] && buffer[size] != '\n')
		size++;
	if (buffer[size] == '\n')
		size++;
	line = (char *)malloc(sizeof(char) * size);
	if (!line)
		return (NULL);
	buffer[size] = '\0';
	while (--size >= 0)
		line[size] = buffer[size];
	return (line);
}

static char	*get_rest(char *buffer)
{
	char	*rest;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		return (free_mem(&buffer));
    }
	rest = ft_substr(buffer, (i + 1), (ft_strlen(buffer) - (i + 1)));
	if (!rest)
		return (NULL);
	free_mem(&buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer[fd] = get_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = get_the_line(buffer[fd]);
	if (!line)
		return (free_mem(&buffer));
	buffer[fd] = get_rest(buffer[fd]);
	return (line);
}
