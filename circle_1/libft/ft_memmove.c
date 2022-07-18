/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:41:25 by hyeslim           #+#    #+#             */
/*   Updated: 2022/07/18 14:25:59 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = NULL;
	while (((unsigned char *)src)[i])
	{
		temp[i] = ((unsigned char *)src)[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		((unsigned char *)dest)[i] = temp[i];
		i++;
	}
	return (dest);
}
