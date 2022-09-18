/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:21:12 by hyeslim           #+#    #+#             */
/*   Updated: 2022/09/18 17:15:04 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	check_fs(char c, va_list ap)
{
	char	*fs;
	char	*idx;
	int		len;

	fs = "cspdiuxX%%";
	idx = ft_strchr(fs, c);
	len = 0;
	if (*idx == 'c')
		len += print_c((char)va_arg(ap, void *));
	else if (*idx == 's')
		len += print_s((char *)va_arg(ap, char *));
	// else if (*idx == 'p')
	// 	len += print_p(va_arg(ap, void *));
	else if (*idx == 'd' || *idx == 'i' || *idx == 'u')
		len += print_diu((int)va_arg(ap, int));
	else if (*idx == 'x' || *idx == 'X')
	{
		if (*idx == 'x')
			len += print_xX((int)va_arg(ap, int), 0);
		else
			len += print_xX((int)va_arg(ap, int), 1);
	}
	return (len);
}

int	count_args(char *str)
{
	int	count;

	count = 0;
	while (*str && *(str + 1))
	{
		if (*str == '%')
		{
			count++;
			str++;
		}
		str++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				len += print_c('%');
			else
			{
				len += check_fs(format[i], ap);
			}
		}
		else
			len += print_c(format[i]);
		i++;
	}
	return (len);
}

			// while (format/* format[i] 가 type 만날때까지 */)
			// 	// 구조체에 각 플래그 할당!
			// if (format[i]/* 현재 인덱스에서 format[i] 가 type인가??  */)
			// 	// 출력모듈로 이동
