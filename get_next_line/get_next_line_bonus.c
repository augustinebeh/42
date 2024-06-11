/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:21:02 by abeh              #+#    #+#             */
/*   Updated: 2024/06/11 01:49:14 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_creator(int fd, char *left_c, char *buffer);
static char	*ft_truncator(char *line_buffer);

void	ft_strdel(char **s)
{
	if (s != NULL && *s != NULL)
	{
		free(*s);
		*s = NULL;
	}
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

char	*get_next_line(int fd)
{
	static char	*b[MAX_FD];
	char		*buffer;
	char		*r;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		ft_strdel(&b[fd]);
		ft_strdel(&buffer);
		return (NULL);
	}
	r = ft_creator(fd, b[fd], buffer);
	ft_strdel(&buffer);
	if (!r)
		return (NULL);
	b[fd] = ft_truncator(r);
	return (r);
}

static char	*ft_truncator(char *r)
{
	char	*b;
	ssize_t	i;

	i = 0;
	while (r[i] != '\n' && r[i] != '\0')
		i++;
	if (r[i] == '\0')
		return (NULL);
	b = ft_substr(r, i + 1, ft_strlen(r) - i);
	if (*b == '\0')
		ft_strdel(&b);
	r[i + 1] = '\0';
	return (b);
}

static char	*ft_creator(int fd, char *b, char *buffer)
{
	ssize_t	br;
	char	*t;

	if (b != NULL && ft_strchr(b, '\n') != NULL)
		return (b);
	while (1)
	{
		br = read(fd, buffer, BUFFER_SIZE);
		if (br == -1)
			return (NULL);
		else if (br == 0)
			break ;
		buffer[br] = '\0';
		if (b == NULL)
			b = ft_strdup("");
		t = b;
		b = ft_strjoin(t, buffer);
		ft_strdel(&t);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (b);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;
// 	int		n;

// 	fd = open("invictus.txt", O_RDONLY);
// 	if (fd == -1)
// 		printf("error");
// 	}
// 	i = 0;
// 	n = 42;
// 	printf("\n");
// 	while (i < n)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 		{
// 			printf("\n");
// 			close(fd);
// 			break ;
// 		}
// 		if(i+1 <10)
// 			printf("line[0%d]:  %s", (i + 1), line);
// 		else
// 			printf("line[%d]:  %s", (i + 1), line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }
