/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:21:02 by abeh              #+#    #+#             */
/*   Updated: 2024/06/06 06:11:48 by abeh             ###   ########.fr       */
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
	char *front_line;
	char *return_line;
	char *buffer;
	ssize_t bytes_read;

	if (balance == NULL)
		balance = ft_strdup("");


	front_line = ft_strdup("");

	buffer = (char*)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buffer)
	{
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		free(balance);
		balance = NULL;
		buffer = NULL;
		return (NULL);
	}
	return_line = ft_strdup("");
	while (ft_strchr(buffer, '\n') == NULL)
	{
		if (ft_strchr(balance, '\n') == NULL)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);

			if (bytes_read < 0)
			{
				free(buffer);
				free(balance);
				balance = NULL;
				buffer = NULL;
				return (NULL);
			}
			else if (bytes_read == 0)
				return NULL;
			buffer[bytes_read] = '\0';
		}
		else
			buffer = balance;
		int count;

		count = 1;

		if (ft_strchr(buffer, '\n') != NULL)
		{
			count = count + fl_len(buffer);
			front_line = ft_substr(buffer, 0, count);
			front_line[count] = '\0';
			if (ft_strchr(balance, '\n') == NULL)
				return_line = ft_strjoin(balance, return_line);
			return_line = ft_strjoin(return_line, front_line);

			balance = ft_strchr(buffer, '\n');
			*balance++;
		}
		else
			return_line = ft_strjoin(return_line, buffer);
	}
	return(return_line);
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
   nth_line = 20;
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
