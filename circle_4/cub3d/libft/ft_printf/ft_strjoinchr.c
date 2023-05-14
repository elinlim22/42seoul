/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:30:14 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/07 15:19:46 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strjoin_print(char **line, char c, ssize_t *sum)
{
	char	*tmp;
	ssize_t	i;

	tmp = ft_malloc(sizeof(char) * (*sum + 1));
	if (!tmp)
		return (-1);
	i = 0;
	while (i < *sum)
	{
		tmp[i] = (*line)[i];
		i++;
	}
	tmp[i] = c;
	if (*line)
		ft_free(*line);
	*line = tmp;
	*sum += 1;
	return (0);
}
