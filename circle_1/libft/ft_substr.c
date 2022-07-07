/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:31:58 by hyeslim           #+#    #+#             */
/*   Updated: 2022/07/07 19:25:01 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * len);
	// if (*dest == 0)
	// 	return (0);
	i = 0;
	while (i + 1 < (int)len)
	{
		dest[i] = s[start + i];
		// dest++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
