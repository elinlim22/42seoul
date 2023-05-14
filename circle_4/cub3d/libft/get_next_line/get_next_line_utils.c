/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:57:44 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/03 12:17:48 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin_lf(char *s1, char *s2)
{
	char	*res;

	res = ft_malloc(sizeof(char) * (ft_strlen_lf(s1) + ft_strlen_lf(s2) + 1));
	if (!res)
	{
		if (s1)
			ft_free(s1);
		return (0);
	}
	_cp(&res, s1, s2);
	if (s1)
		ft_free(s1);
	return (res);
}

void	_cp(char **res, char *s1, char *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;

	i = 0;
	len1 = ft_strlen_lf(s1);
	len2 = ft_strlen_lf(s2);
	while (i < len1)
	{
		(*res)[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		(*res)[i] = s2[i - len1];
		i++;
	}
	(*res)[i] = 0;
}

size_t	ft_strlen_lf(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	if (s && s[i] == '\n')
		i++;
	return (i);
}

int	remain_right(char *buf)
{
	size_t	i;
	size_t	j;
	int		flag;

	flag = 0;
	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	if (buf[i] == '\n')
	{
		flag = 1;
		i++;
	}
	j = 0;
	while (buf[i])
		buf[j++] = buf[i++];
	while (buf[j])
		buf[j++] = 0;
	return (flag);
}
