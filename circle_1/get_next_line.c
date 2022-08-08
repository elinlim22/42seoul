/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:09:27 by hyeslim           #+#    #+#             */
/*   Updated: 2022/08/08 20:24:06 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

static	char	*ft_line(int fd, char *buff, char *backup)
{
	int		size;
	char	*tmp_pnt;

	size = 1;
	while (size)
	{
		size = read(fd, buff, BUFFER_SIZE);
		printf("read error? size is : %d\n", size); ///ok
		if (size == -1) ///case error
			return (NULL);
		if (size == 0) ///case EOF
			break ;
		if (!backup)
			backup = ft_strdup("");
		buff[size] = '\0';
		tmp_pnt = backup;
		printf("buff temp : %s\n", buff); ///ok
		backup = ft_strjoin(tmp_pnt, buff);
		printf("backup temp : %s\n", backup); ///ok
		printf("1 if backup success : %d\n", backup!=0); ///ok
		if (!backup)
			return (NULL);
		free(tmp_pnt);
		tmp_pnt = NULL;
		printf("1 if strchr NL in buff : %d\n", ft_strchr(buff, '\n')!= 0); ///ok
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
	int		i;
	char	*update;

	i = 0;
	printf("NL location is : %d\n", i); ///ok
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
		// return (NULL);
	// if (update[0] == '\0') ///memory leak?
	// {
	// 	free(update);
	// 	update = NULL;
	// 	return (NULL);
	// }
	temp[i + 1] = '\0';
	return (update);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*buff;
	char		*temp;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	// if (!buff)
	// 	return (NULL);
	if (!buff || fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	temp = ft_line(fd, buff, backup[fd]);
	printf("1 if ft_line success : %d\n", temp!=0); ///ok
	free(buff);
	buff = NULL;
	if (!temp)
		return (NULL);
	backup[fd] = ft_update(temp);
	free(temp);
	printf("backup updated : \n------\n%s\n------\n", backup[fd]);
	return (temp);
}

int main(void)
{
  int fd;
  int fd2;

  fd = 0;
  fd = open("test.txt", O_RDONLY);
  printf("%d\n", fd);
  char *line = get_next_line(fd);
  printf("%p\n", line);
  printf("%s", line);


  printf("\n---------------------------------------\n");
  line = get_next_line(fd);
  printf("%p\n", line);
  printf("%s", line);

  printf("\n---------------------------------------\n");
  fd2 = open("test2.txt", O_RDONLY);
  printf("%d\n", fd2);
  char *line2 = get_next_line(fd2);
  printf("%p\n", line2);
  printf("%s", line2);

  printf("\n---------------------------------------\n");
  line = get_next_line(fd);
  printf("%p\n", line);
  printf("%s", line);

  printf("\n---------------------------------------\n");
  system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
  return (0);
}
