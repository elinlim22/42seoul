/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:19:51 by hyeslim           #+#    #+#             */
/*   Updated: 2022/07/07 14:34:23 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i] && (i < len))
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == 0)
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (0);
}
