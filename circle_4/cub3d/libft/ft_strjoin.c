/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:46:40 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/03 11:57:53 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = ft_malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (0);
	res[0] = 0;
	ft_strlcat(res, s1, len1 + len2 + 1);
	ft_strlcat(res, s2, len1 + len2 + 1);
	return (res);
}
