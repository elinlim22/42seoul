/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:34:52 by hyeslim           #+#    #+#             */
/*   Updated: 2022/12/11 21:31:40 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	piper(char *cmd, t_pipex *all)
{
	pid_t	pid;
	int		fd[2];

	pipe_and_fork(&fd, &pid);
	all->last_pid = pid;
	if (pid == CHILD)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(cmd, all->n_av, environ);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		close(fd[0]);
	}
}

void	here_doc(char *limiter)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	pipe_and_fork(&fd, &pid);
	if (pid == CHILD)
	{
		close(fd[0]);
		line = get_next_line(STDIN_FILENO);
		while (ft_strnstr(line, limiter, ft_strlen(limiter)) == 0)
		{
			ft_putstr_fd(line, fd[1]);
			free(line);
			line = get_next_line(STDIN_FILENO);
		}
		free(line);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		exit(0);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		close(fd[0]);
	}
}

int	main(int argc, char *argv[])
{
	t_pipex	all;
	int		i;
	int		res;
	char	*cmd;

	i = 1;
	res = 0;
	get_path(&all);
	if (argc < 5)
		err_msg_fd("arguments invalid", 2, 1);
	if (ft_strnstr(argv[1], "here_doc", 8) != 0)
		opener(&all, argc, argv, 1);
	else
		opener(&all, argc, argv, 0);
	while (++i + all.hd <= argc - 2)
	{
		get_av(&all, argv[i + all.hd]);
		get_cmd(&cmd, all.n_av[0], all.list_path);
		if (i + all.hd != argc - 2)
			piper(cmd, &all);
		else
		{
			dup2(all.fd.out, STDOUT_FILENO);
			get_av(&all, argv[i + all.hd]);
			get_cmd(&cmd, all.n_av[0], all.list_path);
			execve(cmd, all.n_av, environ); //fork하ㄴ번더해!!!
		}
		free(cmd);
	}
	while (i--)
	{
		if (wait(&all.status) == all.last_pid)
			res = all.status;
	}//wait
	return (res);
}
