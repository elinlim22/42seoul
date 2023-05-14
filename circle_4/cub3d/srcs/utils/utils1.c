/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:19:17 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/02 16:03:21 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	rgb_atoi(char **nptr)
{
	int				nbr;
	int				sign;
	unsigned int	i;

	nbr = 0;
	sign = 1;
	i = 0;
	if ((*nptr)[i] == '-')
		sign = -1;
	if ((*nptr)[i] == '-' || (*nptr)[i] == '+')
		i++;
	while ((*nptr)[i] >= '0' && (*nptr)[i] <= '9')
	{
		nbr = (nbr * 10) + ((*nptr)[i++] - '0') * sign;
		if (nbr > 255)
			return (-1);
		if (nbr < 0)
			return (-1);
	}
	*nptr = *nptr + i;
	return (nbr);
}

void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list->str);
		free(list);
		list = tmp;
	}
}

void	free_all(t_arg *arg)
{
	int		i;

	i = -1;
	while (++i < arg->y_size)
		free(arg->map[i]);
	free(arg->map);
	free_arg(arg);
}

void	free_arg(t_arg *arg)
{
	if (arg->root.no)
		free(arg->root.no);
	if (arg->root.so)
		free(arg->root.so);
	if (arg->root.we)
		free(arg->root.we);
	if (arg->root.ea)
		free(arg->root.ea);
	if (arg->root.s1)
		free(arg->root.s1);
	if (arg->root.s2)
		free(arg->root.s2);
	if (arg->root.door)
		free(arg->root.door);
}

bool	free_split(char **split, int flag)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	if (flag)
		return (true);
	return (false);
}
