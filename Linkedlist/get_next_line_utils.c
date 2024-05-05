#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strchr(const char *str, int c)
{
	size_t i;

	i = 0;
	while (i < (ft_strlen(str) + 1))
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	if (size != 0)
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[len])
		len++;
	return (len);
}

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t d_len;
	size_t s_len;

	i = 0;
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (d_len > size || size == 0)
		return (size + s_len);
	while ((i + d_len) < (size - 1) && src[i] != '\0')
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (d_len + s_len);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char *newstr;
	size_t s1_len;
	size_t s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, (s1_len + 1));
	ft_strlcat(newstr, s2, (s1_len + s2_len + 1));
	return (newstr);
}

char *ft_strdup(const char *str)
{
	char *newstr;
	size_t i;

	newstr = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *substr;
	size_t end;
	size_t i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (ft_strlen(s) > start + len)
		end = start + len;
	else
		end = ft_strlen(s);
	substr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}