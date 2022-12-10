/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:34:52 by hyeslim           #+#    #+#             */
/*   Updated: 2022/12/10 20:58:49 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	piper(char *cmd, t_pipex *all)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		err_msg_fd("pipe error", 2, 1);
	pid = fork();
	if (pid == -1)
		err_msg_fd("fork error", 2, 1);
	if (pid == CHILD)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execve(cmd, all->n_av, environ);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	here_doc(char *limiter)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
		err_msg_fd("pipe error", 2, 1);
	pid = fork();
	if (pid == -1)
		err_msg_fd("fork error", 2, 1);
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
		exit(0);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int	main(int argc, char *argv[])
{
	t_pipex	all;
	int		i;
	char	*cmd;

	i = 1;
	get_path(&all);
	if (argc >= 5)
	{
		if (ft_strnstr(argv[1], "here_doc", 8) != 0)
		{
			all.hd = 1;
			all.fd.out = \
				open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
			here_doc(argv[i + all.hd]);
		}
		else
		{
			all.hd = 0;
			all.fd.out = \
				open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			all.fd.in = open(argv[1], O_RDONLY | O_CREAT, 0644);
			dup2(all.fd.in, STDIN_FILENO);
		}
		while (++i + all.hd < argc - 2)
		{
			get_av(&all, argv[i + all.hd]);
			get_cmd(&cmd, all.n_av[0], all.list_path);
			piper(cmd, &all);
			free(cmd);
		}
		dup2(all.fd.out, STDOUT_FILENO);
		get_av(&all, argv[i + all.hd]);
		get_cmd(&cmd, all.n_av[0], all.list_path);
		execve(cmd, all.n_av, environ);
	}
	err_msg_fd("arguments invalid", 2, 1);
}
