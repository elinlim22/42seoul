/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:23:20 by hyeslim           #+#    #+#             */
/*   Updated: 2022/07/06 14:09:53 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	char			c;
	unsigned char	*str;

	i = 0;
	c = (unsigned char)value;
	str = (unsigned char *)ptr;
	while (i < num)
	{
		str[i] = c;
		i++;
	}
	return (ptr);
}
