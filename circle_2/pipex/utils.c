/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:12:01 by hyeslim           #+#    #+#             */
/*   Updated: 2022/12/10 17:32:36 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_cmd(char **cmd, char *argv, char **list)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (!list || !*list)
		err_msg_fd("environ invalid", 2, 1);
	while (list[i])
	{
		tmp = ft_strdup(list[i]);
		if (!ft_strchr(argv, '/'))
			addstr(&tmp, argv);
		if (access(tmp, X_OK) == 0)
		{
			*cmd = tmp;
			return ;
		}
		i++;
		free(tmp);
	}
	err_msg_fd("argument invalid", 2, 127); //EXIT_STATUS == 127
}

void	get_path(t_pipex *pipe)
{
	int	i;

	i = 0;
	while (environ[i])
	{
		if (ft_strnstr(environ[i], "PATH", 4))
		{
			pipe->list_path = ft_split(environ[i] + 5, ':');
			i = 0;
			while (pipe->list_path[i])
				addstr(&(pipe->list_path[i++]), "/");
			return ;
		}
		i++;
	}
	err_msg_fd("PATH unavailable", 2, 1);
}

void	get_av(t_pipex *all, char *argv)
{
	if (all->n_av)
		all->n_av = NULL;
	all->n_av = ft_split(argv, ' ');
	if (!all->n_av) //필요?
		err_msg("n_av split fail");
}
