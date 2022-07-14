/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:15:50 by hyeslim           #+#    #+#             */
/*   Updated: 2022/07/12 15:32:23 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	count_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	printf("%d\n", len);
	return (len);
}

char	*ft_itoa(int n)
{
	int				len;
	int				sign;
	char			*str;
	unsigned int	temp;

	sign = 0;
	len = count_len(n);
	if (n < 0)
	{
		len++;
		sign = 1;
		temp = -n;
	}
	else
		temp = n;
	str = (char *)malloc(sizeof(char) * (len + sign + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	while (len - 1 > sign - 1)
	{
		str[len - 1] = (temp % 10 + '0');
		len--;
		temp /= 10;
	}
	return (str);
}
