/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:21:02 by abeh              #+#    #+#             */
/*   Updated: 2024/06/07 04:31:15 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int fl_len(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		i++;
	}
	if (buffer[i] == '\n')
		i++;
	return(i);
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

char *get_next_line(int fd)
{
	static char *balance = NULL;
	char *return_line;
	char *buffer;
	ssize_t bytes_read;

	if (balance == NULL)
		balance = ft_strdup("");
	buffer = (char*)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (buffer == NULL)
		return (NULL);
	while (ft_strchr(balance, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			return NULL;
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		balance = ft_strjoin(balance, buffer);
		free(buffer);
		buffer = (char*)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
		if (buffer == NULL)
			return (NULL);
	}
	if (ft_strchr(balance, '\n') != NULL)
	{
		return_line = ft_splitter_front(balance);
		balance = ft_splitter_back(balance);
	}
	return(return_line);
}

char *ft_splitter_front(char *balance)
{
	char *temp;
	int i;
	i = 0;
	while (balance[i] != '\n' && balance[i])
	i++;
	if (balance[i++] == '\n')
	{
		temp = ft_substr(balance, 0, i);
	}
	return (temp);
}

char *ft_splitter_back(char *balance)
{
	char *temp;
	int i;
	i = 0;
	while (balance[i] != '\n' && balance[i])
	i++;
	if (balance[i++] == '\n')
	{
		temp = ft_substr(balance, i, ft_strlen(balance) - i);
		free(balance);
	}
	return (temp);
}


int main()
{
   int fd;
   char *line;
   int i;
	int	nth_line;

   fd = open("invictus.txt", O_RDONLY);
   if (fd == -1)
   {
      perror("open");
      return (1);
   }
   i = 0;
   nth_line = 42;
   printf("\n");
   while (i < nth_line)
   {
      line = get_next_line(fd);
      if (line == NULL)
      {
         printf("\n");
         close(fd);
         break;
      }
      printf("line[%d]: %s", (i + 1), line);
		free(line);
      i++;
   }
   close(fd);
   return (0);
}

