/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _d_i_u_x_X_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:22:32 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/07 15:20:10 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	_d_i(va_list *ap, char **line, ssize_t *sum)
{
	int	n;

	n = va_arg(*ap, int);
	return (ft_putnbr_d_i(line, n, sum));
}

int	_u(va_list *ap, char **line, ssize_t *sum)
{
	unsigned int	n;

	n = va_arg(*ap, unsigned int);
	return (ft_putnbr_u(line, n, sum));
}

int	_lower_x(va_list *ap, char **line, ssize_t *sum)
{
	unsigned int	n;

	n = va_arg(*ap, unsigned int);
	return (ft_putnbr_x(line, n, sum, 'x'));
}

int	_upper_x(va_list *ap, char **line, ssize_t *sum)
{
	unsigned int	n;

	n = va_arg(*ap, unsigned int);
	return (ft_putnbr_x(line, n, sum, 'X'));
}

int	_p(va_list *ap, char **line, ssize_t *sum)
{
	void				*p;
	unsigned long long	addr_int;

	p = va_arg(*ap, void *);
	addr_int = (unsigned long long)p;
	if (ft_strjoin_print(line, '0', sum) == -1)
		return (-1);
	if (ft_strjoin_print(line, 'x', sum) == -1)
		return (-1);
	return (ft_putnbr_x(line, addr_int, sum, 'x'));
}
