/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:28:14 by hyeslim           #+#    #+#             */
/*   Updated: 2022/07/07 19:09:39 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;
	size_t	i;

	dest = malloc(size * count);
	if (*((char *)dest) == 0)
		return (0);
	i = 0;
	ft_memset(dest, 0, count);
	return (dest);
}
