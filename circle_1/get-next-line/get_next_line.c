/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:09:27 by hyeslim           #+#    #+#             */
/*   Updated: 2022/08/02 17:18:11 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*ft_line(int fd, char *buff, char *backup)
{
	int	size;

	size = 1;
	while (size)
	{
		if (!buff)
			buff = ft_strdup("");
		size = read(fd, buff, BUFFER_SIZE);
		if (size == 0)
			return (NULL);
		buff[size] = '\0';
		backup = ft_strjoin(backup, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buff;
	char		*temp;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff || fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff, BUFFER_SIZE) == -1)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	if (!buff)
		return (NULL);
	temp = ft_line(fd, buff, backup);
	free(buff);
	buff = NULL;
	if (!temp)
		return (NULL);
	return (temp);
}
