/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:51:04 by hyeslim           #+#    #+#             */
/*   Updated: 2022/12/05 16:23:36 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

# define STDOUT_HD (2)
# define CHILD (0)
# define ERROR (-1)

typedef struct s_pipe
{
	int	hd;
	int	fd_in;
	int	fd_out;
}				t_pipe;

typedef struct s_args
{
	int		argc;
	char	**argv;
	char	**envp;
}				t_args; //굳이?


// main
int		opener(char *file, int status);
void	piper(t_pipe *pipe, t_args *args, char **list_path);
void	forker(char *argv, char **list_path);

// utils
char	**get_path(char **envp);
void	execve_path(char **list_path, char *cmd, char **argv, char **envp);


#endif
