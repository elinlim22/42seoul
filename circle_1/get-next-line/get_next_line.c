/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:09:27 by hyeslim           #+#    #+#             */
/*   Updated: 2022/08/09 15:30:09 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*ft_line(int fd, char *buff, char *backup)
{
	int		size;
	char	*tmp_pnt;

	size = 1;
	while (size)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == -1)
			return (NULL);
		if (size == 0)
			break ;
		if (!backup)
			backup = ft_strdup("");
		buff[size] = '\0';
		tmp_pnt = backup;
		backup = ft_strjoin(tmp_pnt, buff);
		if (!backup)
			return (NULL);
		free(tmp_pnt);
		tmp_pnt = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (backup);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while ((i < len) && *(s + start + i))
	{
		*(dest + i) = *(s + start + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

static char	*ft_update(char *temp)
{
	char	*update;
	int		i;

	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if (temp[i] == '\0')
		return (NULL);
	update = ft_substr(temp, i + 1, ft_strlen(temp) - i - 1);
	if (!update || update[0] == '\0')
	{
		free(update);
		update = NULL;
		return (NULL);
	}
	temp[i + 1] = '\0';
	// free(temp); ///free 해야하나?
	return (update);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buff;
	char		*temp;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff || fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	temp = ft_line(fd, buff, backup);
	free(buff);
	buff = NULL;
	if (!temp)
		return (NULL);
	backup = ft_update(temp);
	return (temp);
}


// #include <fcntl.h>
// #include <stdio.h>

// int main(void)
// {
//   int fd;

//   fd = 0;
//   fd = open("test.txt", O_RDONLY);
//   printf("%d\n", fd);
//   char *line = get_next_line(fd);
//   printf("%p\n", line);
//   printf("%s", line);

//   printf("\n---------------------------------------\n");
//   line = get_next_line(fd);
//   printf("%p\n", line);
//   printf("%s", line);

//   printf("\n---------------------------------------\n");
//   line = get_next_line(fd);
//   printf("%p\n", line);
//   printf("%s", line);

//   printf("\n---------------------------------------\n");
//   line = get_next_line(fd);
//   printf("%p\n", line);
//   printf("%s", line);

//   printf("\n---------------------------------------\n");
//   system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
//   return (0);
// }
