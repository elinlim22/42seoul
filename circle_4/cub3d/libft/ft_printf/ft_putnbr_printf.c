/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:57:07 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/07 15:22:03 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr_d_i(char **line, long long n, ssize_t *sum)
{
	char	c;

	if (n < 0)
	{
		if (ft_strjoin_print(line, '-', sum) == -1)
			return (-1);
		n *= -1;
		if (ft_putnbr_d_i(line, n, sum) == -1)
			return (-1);
	}
	else if (n >= 10)
	{
		if (ft_putnbr_d_i(line, n / 10, sum) == -1)
			return (-1);
		c = n % 10 + '0';
		if (ft_strjoin_print(line, c, sum) == -1)
			return (-1);
	}
	else
	{
		c = n % 10 + '0';
		if (ft_strjoin_print(line, c, sum) == -1)
			return (-1);
	}
	return (0);
}

int	ft_putnbr_u(char **line, unsigned long long n, ssize_t *sum)
{
	char	c;

	if (n >= 10)
	{
		if (ft_putnbr_u(line, n / 10, sum) == -1)
			return (-1);
		c = n % 10 + '0';
		if (ft_strjoin_print(line, c, sum) == -1)
			return (-1);
	}
	else
	{
		c = n % 10 + '0';
		if (ft_strjoin_print(line, c, sum) == -1)
			return (-1);
	}
	return (0);
}

int	ft_putnbr_x(char **line, unsigned long long n, ssize_t *sum, char flag)
{
	char	c;

	if (n >= 16)
	{
		if (ft_putnbr_x(line, n / 16, sum, flag) == -1)
			return (-1);
		c = set_c_x(n, flag);
		if (ft_strjoin_print(line, c, sum) == -1)
			return (-1);
	}
	else
	{
		c = set_c_x(n, flag);
		if (ft_strjoin_print(line, c, sum) == -1)
			return (-1);
	}
	return (0);
}

char	set_c_x(unsigned long long n, char flag)
{
	char	c;

	if (n % 16 < 10)
		c = n % 16 + '0';
	else
	{
		if (flag == 'x')
			c = n % 16 - 10 + 'a';
		else if (flag == 'X')
			c = n % 16 - 10 + 'A';
		else
			c = 0;
	}
	return (c);
}
