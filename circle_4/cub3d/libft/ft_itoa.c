/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:06:48 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/07 19:51:43 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit(int n);
static void	set_digit(int n, int flag, int len, char *res);

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		flag;

	len = 0;
	flag = 0;
	if (n < 0)
		flag = 1;
	len += get_digit(n);
	res = ft_malloc(sizeof(char) * (len + flag + 1));
	if (!res)
		return (0);
	if (flag)
		res[0] = '-';
	res[len + flag] = 0;
	set_digit(n, flag, len, res);
	return (res);
}

static int	get_digit(int n)
{
	int	res;

	if (n == 0)
		return (1);
	res = 0;
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

static void	set_digit(int n, int flag, int len, char *res)
{
	int	div;

	div = flag;
	while ((len - 1 >= 0))
	{
		if (div)
		{
			res[len + flag - 1] = (n % 10) * -1 + '0';
			n /= -10;
			div = 0;
		}
		else
		{
			res[len + flag - 1] = n % 10 + '0';
			n /= 10;
		}
		len--;
	}
}
