/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:12:01 by hyeslim           #+#    #+#             */
/*   Updated: 2022/12/08 17:37:35 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd(char *argv, char **list)
{
	int	i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (list[i])
	{
		tmp = ft_strdup(list[i]);
		if (!ft_strchr(argv, '/')) //strchr 함수 리턴값 확인 필요
			addstr(&tmp, argv);
		// tmp = ft_strjoin(tmp, argv);
		if (access(tmp, X_OK) == 0)
			return (tmp);
		free(tmp);
		i++;
	}
	return (NULL);
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
	err_msg_fd("no path", 2);
}

void	get_av(t_pipex *all, char *argv)
{
	// char	**n_av;
	if (all->n_av)
		all->n_av = NULL;
	all->n_av = ft_split(argv, ' ');
	if (!all->n_av) //필요?
		err_msg("n_av split fail");
	// return (n_av);
}
