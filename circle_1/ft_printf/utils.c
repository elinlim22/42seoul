/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:50:41 by hyeslim           #+#    #+#             */
/*   Updated: 2022/09/13 17:09:44 by hyeslim          ###   ########.fr       */
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

int print_p(void *pt)
{
	char	*address;

	address = &pt;
	ft_putstr_fd(address, 1);
	return (ft_strlen(address));
}

int	print_diu(int i)
{
	ft_putnbr_fd(i, 1));
	return (1);
}

int print_xX(int i, int lu)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (lu)
		ft_strupcase(hex);
	print_c(hex[(unsigned char)c / 16]);
	print_c(hex[(unsigned char)c % 16]);
	return (1);
}

// void	hex_print(char c, int lu)
// {
// 	char	*hex;

// 	hex = "0123456789abcdef";
// 	if (lu)
// 		ft_strupcase(hex);
// 	ft_putchar('\\');
// 	ft_putchar(hex[(unsigned char)c / 16]);
// 	ft_putchar(hex[(unsigned char)c % 16]);
// 	return (1);
// }

// static int	is_lowercase(char c)
// {
// 	return ((c >= 'a' && c <= 'z'));
// }

void	ft_strupcase(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= ('a' - 'A');
		str++;
	}
}
