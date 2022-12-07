/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:35:12 by hyeslim           #+#    #+#             */
/*   Updated: 2022/12/07 23:01:16 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

# define CHILD (0)

typedef struct s_fd
{
	int	in;
	int	out;
}				t_fd;

typedef struct s_pipex
{
	int		hd;
	t_fd	fd;
	char	**list_path;
	char	**n_av;
}				t_pipex;

void	piper(char *cmd, t_pipex *all);

extern char	**environ;


char	*get_cmd(char *argv, char **list);
void	get_path(t_pipex *pipe);
void	get_av(t_pipex *all, char *argv);



#endif
