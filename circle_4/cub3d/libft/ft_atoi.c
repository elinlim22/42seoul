/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:04:33 by dongyoki          #+#    #+#             */
/*   Updated: 2023/02/23 16:53:40 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char *nptr, int i)
{
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	return (i);
}

bool	ft_atoi(const char *nptr, int *num)
{
	int		i;
	size_t	temp;

	temp = (size_t)(*num);
	i = ft_isspace(nptr, 0);
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			return (false);
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		temp = temp * 10 + (nptr[i] - '0');
		i++;
		if (temp > INT_MAX)
			return (false);
	}
	if (nptr[i] != '\n' && (nptr[i] || temp == 0))
		return (false);
	*num = (int)temp;
	return (true);
}
