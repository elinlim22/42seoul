/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:49:01 by hyeslim           #+#    #+#             */
/*   Updated: 2022/12/13 20:41:30 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	opener(t_pipex *all, int argc, char **argv);
void	pipe_and_fork(int (*fd)[2], pid_t *pid);
void	fork_last(t_pipex *all);
void	do_cmds(t_pipex *all, int end, char **argv, int *i);

void	opener(t_pipex *all, int argc, char **argv)
{
	all->hd = 0;
	all->fd.out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	all->fd.in = open(argv[1], O_RDONLY, 0644);
	if (all->fd.out == -1 && all->fd.in == -1)
		err_msg_fd("Permission denied", 2, 1);
	dup2(all->fd.in, STDIN_FILENO);
}

void	pipe_and_fork(int (*fd)[2], pid_t *pid)
{
	if (pipe(*fd) == -1)
		err_msg_fd("pipe error", 2, 1);
	*pid = fork();
	if (*pid == -1)
		err_msg_fd("fork error", 2, 1);
}

void	fork_last(t_pipex *all)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execve(all->cmd, all->n_av, environ);
		perror(all->cmd);
		exit(1);
	}
}

void	do_cmds(t_pipex *all, int end, char **argv, int *i)
{
	while (++(*i) + all->hd <= end)
	{
		all->n_av = NULL;
		if ((*i) + all->hd != end)
			piper(all, argv, i);
		else
		{
			dup2(all->fd.out, STDOUT_FILENO);
			get_list(all, argv, (*i));
			fork_last(all);
		}
		free(all->cmd);
	}
}
