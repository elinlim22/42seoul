/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:28:14 by hyeslim           #+#    #+#             */
/*   Updated: 2022/07/07 16:33:29 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_memset.c"
void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;
	size_t	i;

	dest = malloc(size * count);
	if (*dest == 0)
		return (0);
	i = 0;
	ft_memset(dest, 0, count);
	return (dest);
}
