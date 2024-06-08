/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:21:02 by abeh              #+#    #+#             */
/*   Updated: 2024/06/09 02:12:33 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_creator(int fd, char *left_c, char *buffer);

static char	*ft_truncator(char *line_buffer);

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			find;

	find = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == find)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == find)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*str;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i <= len)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

char	*get_next_line(int fd)
{
	static char	*b;
	char		*r;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE - BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || fcntl(fd, F_GETFL) == -1)
	{
		free(b);
		free(buffer);
		b = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	r = ft_creator(fd, b, buffer);
	free(buffer);
	buffer = NULL;
	if (!r)
		return (NULL);
	b = ft_truncator(r);
	return (r);
}

// Function purpose:
//	1. return the leftover portion of the string
// 2. truncate after the first '\n'
static char	*ft_truncator(char *r)
{
	char	*b;
	ssize_t	i;

	i = 0;
	while (r[i] != '\n' && r[i] != '\0')
		i++;
	if (r[i] == 0 || r[1] == 0)
		return (NULL);
	b = ft_substr(r, i + 1, ft_strlen(r) - i);
	if (*b == '\0')
	{
		free(b);
		b = NULL;
	}
	r[i + 1] = '\0';
	return (b);
}

// Function purpose:
// keep reading until we find a '\n' character
static char	*ft_creator(int fd, char *b, char *buffer)
{
	ssize_t	br;
	char	*t;

	br = 1;
	while (br > 0)
	{
		br = read(fd, buffer, BUFFER_SIZE);
		if (br == -1)
		{
			free(b);
			return (NULL);
		}
		else if (br == 0)
			break ;
		buffer[br] = '\0';
		if (b == NULL)
			b = ft_strdup("");
		t = b;
		b = ft_strjoin(t, buffer);
		free(t);
		t = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (b);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;
	int		n;

	fd = open("invictus.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	i = 0;
	n = 42;
	printf("\n");
	while (i < n)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			printf("\n");
			close(fd);
			break ;
		}
		printf("line[%d]: %s", (i + 1), line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
