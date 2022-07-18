/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:31:58 by hyeslim           #+#    #+#             */
/*   Updated: 2022/07/18 20:05:26 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!s)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	i = 0;
	while ((i < len) && *(s + start + i))
	{
		*(dest + i) = *(s + start + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
