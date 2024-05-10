/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:18:27 by jingwu            #+#    #+#             */
/*   Updated: 2024/05/10 08:42:09 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	*free_mem(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	size_t i;

	if (!str)
		return (NULL);
	i = 0;
	while (i < (ft_strlen(str) + 1))
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *dest, char *src)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!dest && !src)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(src) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (dest[i])
	{
		new_str[i] = dest[i];
		i++;
	}
	while (src[j])
		new_str[i++] = src[j++];
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		substr = (char *)malloc(sizeof(char));
		if (!substr)
			return (NULL);
		*substr = '\0';
		return (substr);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (s[i] && i <= len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

