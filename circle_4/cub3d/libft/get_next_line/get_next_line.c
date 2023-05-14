/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmin <youngmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:57:40 by dongyoki          #+#    #+#             */
/*   Updated: 2023/02/25 16:01:19 by youngmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*get_next_line(int fd)
{
	static t_manage	*lst;
	t_manage		*file;
	char			*line;

	if (fd < 0 || 100 + 1 < 2)
		return (0);
	file = find_file(&lst, fd);
	if (!file)
		file = lstnewadd(&lst, fd);
	if (!file)
		return (0);
	line = loop(file->fd, file->buf);
	if (!line)
		del_file(&lst, fd);
	return (line);
}

char	*loop(int fd, char *buf)
{
	char	*line;
	ssize_t	rd_size;

	line = 0;
	while (1)
	{
		line = ft_strjoin_lf(line, buf);
		if (!line)
			return (0);
		if (remain_right(buf))
			break ;
		rd_size = read(fd, buf, 100);
		if (rd_size <= 0)
			break ;
		buf[rd_size] = 0;
	}
	if (line && (line[0] == 0 || rd_size < 0))
	{
		ft_free(line);
		line = 0;
	}
	return (line);
}

t_manage	*lstnewadd(t_manage **lst, int fd)
{
	t_manage	*res;
	size_t		i;

	res = ft_malloc(sizeof(t_manage));
	if (!res)
		return (0);
	res->fd = fd;
	res->next = *lst;
	res->buf = ft_malloc(sizeof(char) * (100 + 1));
	if (!res->buf)
	{
		ft_free(res);
		return (0);
	}
	i = 0;
	while (i <= 100)
		res->buf[i++] = 0;
	*lst = res;
	return (res);
}

t_manage	*find_file(t_manage **lst, int fd)
{
	t_manage	*file;

	if (!(*lst))
		return (0);
	file = *lst;
	while (file)
	{
		if (file->fd == fd)
			return (file);
		else
			file = file->next;
	}
	return (0);
}

ssize_t	del_file(t_manage **lst, int fd)
{
	t_manage	*file;
	t_manage	*pre;

	file = *lst;
	pre = 0;
	while (file && (file->fd) != fd)
	{
		pre = file;
		file = file->next;
	}
	if (!file)
		return (1);
	if (pre && file)
		pre->next = file->next;
	else if (!pre && file)
		*lst = file->next;
	if (file->buf)
	{
		ft_free(file->buf);
		file->buf = 0;
	}
	ft_free(file);
	return (1);
}
