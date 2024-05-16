/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 08:23:11 by jingwu            #+#    #+#             */
/*   Updated: 2024/05/16 08:23:11 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

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
			return (free_mem(&buffer));
		}
		if (read_bytes == 0)
			break ;
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
	if (!buffer)
		return (NULL);
	while (buffer[size] && buffer[size] != '\n')
		size++;
	if (buffer[size] == '\n')
		size++;
	line = ft_substr(buffer, 0, size);
	if (!line)
		return (NULL);
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
	if (!buffer[i] || !buffer[i + 1])
	{
		rest = NULL;
		return (free_mem(&buffer));
	}
	rest = ft_substr(buffer, (i + 1), (ft_strlen(buffer) - (i + 1)));
	if (!rest)
		return (free_mem(&buffer));
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
		return (free_mem(&buffer[fd]));
	buffer[fd] = get_rest(buffer[fd]);
	return (line);
}
