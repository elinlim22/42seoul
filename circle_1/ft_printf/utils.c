/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:50:41 by hyeslim           #+#    #+#             */
/*   Updated: 2022/09/19 17:37:25 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	print_c(char c)
{
	return (write(1, &c, 1));
}

int print_s(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

// int print_p(unsigned long pt)
// {

// 	return ();
// }

int	print_diu(int i)
{
	ft_putnbr_fd(i, 1);
	return (1);
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
	char	*hex;
	int		res;

	hex = "0123456789abcdef";
	res = 0;
	if (lu)
		ft_strupcase(hex);
	res += print_c(hex[i / 16]);
	if (i > 0) /*재귀재귀..*/
	{
		i %= 16;
		print_xX(i, lu);
	}
	return (res);
}
