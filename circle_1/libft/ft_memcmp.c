/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:05:10 by hyeslim           #+#    #+#             */
/*   Updated: 2022/07/06 22:17:28 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (ft_strlen((const char *)s1) == 0 && ft_strlen((const char *)s2) == 0)
		return (0);
	while (i < n)
	{
		if (*(const char *)s1 != *(const char *)s2)
			return (*(const char *)s1 - *(const char *)s2);
		i++;
		s1++;
		s2++;
	}
	return (0);
}
