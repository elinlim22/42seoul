
#include "pipex.h"

void	opener(t_pipex *all, int argc, char **argv, int p_case)
{
	if (p_case == 1)
	{
		all->hd = 1;
		all->fd.out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		here_doc(argv[2]);
	}
	else if (p_case == 0)
	{
		all->hd = 0;
		all->fd.out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		all->fd.in = open(argv[1], O_RDONLY | O_CREAT, 0644);
		dup2(all->fd.in, STDIN_FILENO);
	}
}

void	pipe_and_fork(int (*fd)[2], pid_t *pid)
{
	if (pipe(*fd) == -1)
		err_msg_fd("pipe error", 2, 1);
	*pid = fork();
	if (*pid == -1)
		err_msg_fd("fork error", 2, 1);
}
