/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:50:41 by hyeslim           #+#    #+#             */
/*   Updated: 2022/09/22 17:12:57 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int print_s(char *str)
{
	return (ft_putstr_fd(str, 1));
}

int print_p(void *pt)
{
	unsigned long	ptr;
	char			*hex;
	static int		res;

	ptr = (unsigned long)pt;
	hex = "0123456789abcdef";
	res = 0;
	if (ptr > 0)
	{
		print_p((void *)(ptr / 16));
		res += ft_putchar_fd(hex[ptr % 16], 1);
	}
	return (res);
}

int	print_diu(int i)
{
	return (ft_putnbr_fd(i, 1));
}

void	ft_strupcase(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= ('a' - 'A');
		str++;
	}
}

int print_xX(unsigned int i, int lu)
{
	char		*hex;
	static int	res;

	hex = "0123456789abcdef";
	res = 0;
	if (lu)
		ft_strupcase(hex);
	if (i > 0)
	{
		print_xX(i / 16, lu);
		res += ft_putchar_fd(hex[i % 16], 1);
	}
	return (res);
}
