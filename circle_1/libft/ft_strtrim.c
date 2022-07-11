/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:30:58 by hyeslim           #+#    #+#             */
/*   Updated: 2022/07/11 22:04:27 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (s1[i] && *(ft_strchr(set, s1[i])))
		i++;
	while (s1[j] && *(ft_strchr(set, s1[j])))
	{
		if (j < 0)
			break ;
		j--;
	}
	if (i > j)
		return (ft_strdup(""));
	dest = (char *)malloc(sizeof(char) * (j - i + 2));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1 + i, j - i + 2);
	return (dest);
}
