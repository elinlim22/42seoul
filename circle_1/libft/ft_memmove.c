/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:41:25 by hyeslim           #+#    #+#             */
/*   Updated: 2022/07/19 19:51:28 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = -1;
	if (dest < src)
	{
		while (++i < len)
			d[i] = s[i];
	}
	else
	{
		while (++i < len)
			d[ft_strlen(dest) - i - 1] = s[ft_strlen(src) - i - 1];
	}
	return (dest);
}
