/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:05:25 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/03 11:58:18 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	len;
	char	*res;

	i = 0;
	while (((char *)s1)[i] && is_in_set(((char *)s1)[i], set))
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (i > 0 && is_in_set(((char *)s1)[i], set))
	{
		i--;
		if (i == 0)
			break ;
	}
	if (i + 1 < start)
		len = 0;
	else
		len = i - start + 1;
	res = ft_malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	ft_strlcpy(res, s1 + start, len + 1);
	return (res);
}

static int	is_in_set(char c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}
