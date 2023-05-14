/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:28:55 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/07 15:19:34 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	ssize_t	sum;
	char	*line;

	va_start(ap, str);
	sum = 0;
	line = 0;
	if (parse(str, &ap, &sum, &line) == -1)
	{
		if (line)
			ft_free(line);
		return (-1);
	}
	va_end(ap);
	if (write(1, line, sum) != sum)
	{
		if (line)
			ft_free(line);
		return (-1);
	}
	if (line)
		ft_free(line);
	return (sum);
}

int	parse(const char *str, va_list *ap, ssize_t *sum, char **line)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			if (ft_strjoin_print(line, str[i], sum) == -1)
				return (-1);
		}
		else
		{
			i++;
			if (process(line, sum, str[i], ap) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

int	process(char **line, ssize_t *sum, char flag, va_list *ap)
{
	if (flag == 'c')
		return (_c(ap, line, sum));
	else if (flag == 's')
		return (_s(ap, line, sum));
	else if (flag == 'p')
		return (_p(ap, line, sum));
	else if (flag == 'd' || flag == 'i')
		return (_d_i(ap, line, sum));
	else if (flag == 'u')
		return (_u(ap, line, sum));
	else if (flag == 'x')
		return (_lower_x(ap, line, sum));
	else if (flag == 'X')
		return (_upper_x(ap, line, sum));
	else if (flag == '%')
		return (_per(line, sum));
	else
		return (-1);
	return (0);
}
