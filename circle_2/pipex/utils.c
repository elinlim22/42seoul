/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:39:39 by hyeslim           #+#    #+#             */
/*   Updated: 2022/12/07 14:22:08 by hyeslim          ###   ########.fr       */
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

void	execve_path(char **list_path, char *cmd, char **argv, char **envp)
{
	char *tmp;
	while (*list_path)
	{
		tmp = *list_path;
		addstr(&tmp, cmd);
		if (!access(tmp, X_OK))
			if (execve(tmp, argv, envp) == -1)
				err_msg_fd("cannot exec the command", 2);
		else
			*list_path++;
	}
	err_msg_fd("no sufficient PATH", 2);
}
