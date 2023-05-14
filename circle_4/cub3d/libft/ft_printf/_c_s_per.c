/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _c_s_per.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:21:35 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/07 15:20:24 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	_c(va_list *ap, char **line, ssize_t *sum)
{
	char	c;

	c = va_arg(*ap, int);
	if (ft_strjoin_print(line, c, sum) == -1)
		return (-1);
	return (0);
}

int	_s(va_list *ap, char **line, ssize_t *sum)
{
	char	*s;
	size_t	len;
	size_t	i;

	s = va_arg(*ap, char *);
	if (!s)
	{
		i = 0;
		while (i < 6)
		{
			if (ft_strjoin_print(line, "(null)"[i++], sum) == -1)
				return (-1);
		}
		return (0);
	}
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		if (ft_strjoin_print(line, s[i++], sum) == -1)
			return (-1);
	}
	return (0);
}

int	_per(char **line, ssize_t *sum)
{
	if (ft_strjoin_print(line, '%', sum) == -1)
		return (-1);
	return (0);
}
