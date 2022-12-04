/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:39:39 by hyeslim           #+#    #+#             */
/*   Updated: 2022/12/04 22:01:43 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **envp)
{
	int		i;
	char	**res;

	i = 0;
	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH", 4))
		{
			res = ft_split(*envp + 5, ':');
			return (res);
		}
		(*envp)++;
	}
	return (NULL);
}
