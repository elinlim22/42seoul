/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:36:10 by hyeslim           #+#    #+#             */
/*   Updated: 2022/07/07 15:23:21 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n *= 10;
		n += *str - '0';
		str++;
	}
	return (n * i);
}

#include <stdio.h>
#include <stdlib.h>

int	main(int argc __attribute__((unused)), char *argv[])
{
	if (argc == 1)
	{
		printf("%d\n", atoi("    \v  +35"));
		printf("my result : %d\n", ft_atoi("    \v  +35"));
	}
	else
	{
		printf("%d\n", atoi(argv[1]));
		printf("my result : %d\n", ft_atoi(argv[1]));
	}
	return 0;
}
