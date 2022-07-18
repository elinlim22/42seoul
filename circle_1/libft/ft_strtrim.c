/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:30:58 by hyeslim           #+#    #+#             */
/*   Updated: 2022/07/18 20:25:10 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (s1[i] && *(ft_strchr(set, s1[i])))
		i++;
	if (i > j - 1)
		return (ft_strdup(""));
	while (s1[j - 1] && *(ft_strchr(set, s1[j - 1])))
	{
		if (j - 1 < 0)
			break ;
		j--;
	}
	dest = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1 + i, j - i + 1);
	return (dest);
}
