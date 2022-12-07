/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:39:39 by hyeslim           #+#    #+#             */
/*   Updated: 2022/12/07 14:45:33 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_path(t_pipe *pipe, char **envp)
{
	int		i;

	i = 0;
	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH", 4))
			pipe->list_path = ft_split(*envp + 5, ':');
		(*envp)++;
	}
	return ;
}

void	execve_path(t_pipe *pipe, char *cmd, char **argv, char **envp)
{
	char *tmp;
	while (*(pipe->list_path))
	{
		tmp = *(pipe->list_path);
		addstr(&tmp, cmd);
		if (!access(tmp, X_OK))
		{
			execve(tmp, argv, envp);
			err_msg_fd("cannot exec the command", 2);
		}
		else
			*(pipe->list_path)++;
	}
	err_msg_fd("no sufficient PATH", 2);
}
