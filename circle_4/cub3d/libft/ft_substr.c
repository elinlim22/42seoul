/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:46:43 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/03 11:58:23 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	slen;

	slen = ft_strlen(s);
	if (start >= slen)
	{
		start = 0;
		len = 0;
	}
	if (start + len > slen)
		len = slen - start;
	res = ft_malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	ft_strlcpy(res, (char *)s + start, len + 1);
	return (res);
}
