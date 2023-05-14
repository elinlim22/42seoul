/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:54:43 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/03 11:57:09 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c);
static void		set_words(char const *s, char c, char **res);
static char		*ft_strndup(char *src, size_t src_len);
static char		**free_inside(char **res, size_t total_words);

char	**ft_split(char const *s, char c)
{
	size_t	total_words;
	char	**res;
	size_t	i;

	total_words = count_words(s, c);
	res = ft_malloc(sizeof(char *) * (total_words + 1));
	if (!res)
		return (0);
	res[total_words] = 0;
	set_words(s, c, res);
	i = 0;
	while (i < total_words)
		if (!res[i++])
			return (free_inside(res, total_words));
	return (res);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	res;
	int		flag;

	flag = 0;
	res = 0;
	i = 0;
	while (1)
	{
		if (((char *)s)[i] == c || ((char *)s)[i] == 0)
		{
			if (flag == 1)
				res++;
			flag = 0;
		}
		else
			flag = 1;
		if (!((char *)s)[i])
			break ;
		i++;
	}
	return (res);
}

static void	set_words(char const *s, char c, char **res)
{
	size_t	i;
	size_t	len;
	size_t	start;
	size_t	cnt;

	len = 0;
	cnt = 0;
	i = 0;
	while (1)
	{
		if (((char *)s)[i] == c || ((char *)s)[i] == 0)
		{
			if (len)
				res[cnt++] = ft_strndup((char *)s + start, len);
			len = 0;
		}
		else
		{
			if (!len)
				start = i;
			len++;
		}
		if (!((char *)s)[i++])
			break ;
	}
}

static char	*ft_strndup(char *src, size_t src_len)
{
	char	*dest;
	size_t	i;

	dest = ft_malloc(sizeof(char) * (src_len + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i < src_len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

static char	**free_inside(char **res, size_t total_words)
{
	size_t	i;

	i = 0;
	while (i < total_words)
	{
		if (res[i])
			ft_free(res[i]);
		i++;
	}
	ft_free(res);
	return (0);
}
