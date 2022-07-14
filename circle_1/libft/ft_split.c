/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:10:20 by hyeslim           #+#    #+#             */
/*   Updated: 2022/07/14 11:15:36 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void

static size_t	count_row(char *s, char c)
{
	size_t	count;
	size_t	flag;

	count = 0;
	flag = 0;
	if (*s == 0)
		return (0);
	while (*s)
	{
		if (*s == c)
			flag = 1;
		if (*s != c && (flag || !*(s + 1)))
		{
			flag = 0;
			count++;
		}
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	row;

	row = count_row(s, c);
	result = (char **)malloc(sizeof(char *) * (row + 1));
	if (!result)
		return (NULL);
}
