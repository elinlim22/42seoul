/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:28:34 by hyeslim           #+#    #+#             */
/*   Updated: 2022/07/11 18:15:46 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(dst);
	while (src[i])
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[i + j] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*temp;
	size_t		i;
	size_t		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (i == 0 && j == 0)
		return (0);
	temp = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!temp)
		return (0);
	temp[0] = '\0';
	ft_strcat(temp, s1);
	ft_strcat(temp, s2);
	return (temp);
}








// #include <stdlib.h>

// char	*ft_strcat(char *dest, char *src)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (dest[i])
// 		i++;
// 	while (src[j])
// 	{
// 		dest[i] = src[j];
// 		i++;
// 		j++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// char	*mall_check(char *str, int size, char *sep, int len)
// {
// 	int		tot_len;

// 	tot_len = (size - 1) * ft_strlen(sep) + len + 1;
// 	if (size == 0)
// 	{
// 		str = (char *)malloc(sizeof(char));
// 		if (str == 0)
// 			return (0);
// 	}
// 	else
// 	{
// 		str = (char *)malloc(sizeof(char) * tot_len);
// 		if (str == 0)
// 			return (0);
// 	}
// 	return (str);
// }

// char	*ft_strjoin(int size, char **strs, char *sep)
// {
// 	char	*str;
// 	int		i;
// 	int		len;

// 	i = 0;
// 	len = 0;
// 	str = 0;
// 	while (i < size)
// 	{
// 		len += ft_strlen(strs[i]);
// 		i++;
// 	}
// 	str = mall_check(str, size, sep, len);
// 	if (str != 0)
// 	{
// 		i = 0;
// 		str[0] = 0;
// 		while (i < size)
// 		{
// 			str = ft_strcat(str, strs[i]);
// 			if (i < size - 1)
// 				str = ft_strcat(str, sep);
// 			i++;
// 		}
// 	}
// 	return (str);
// }
