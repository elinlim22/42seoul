/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:34:52 by hyeslim           #+#    #+#             */
/*   Updated: 2022/12/09 23:14:26 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	piper(char *cmd, t_pipex *all)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid == -1)
		err_msg_fd("fork error", 2);
	if (pid == CHILD)
	{
		// const char *test[2] = {"/bin/ls", "-al"};
		// execve("/bin/ls", test, envp);
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		// ft_putstr_fd(cmd, 2);
		// ft_putstr_fd("\n", 2);
		// ft_putstr_fd(all->n_av[0], 2);
		// ft_putstr_fd("\n", 2);
		// ft_putstr_fd(all->n_av[1], 2);
		// ft_putstr_fd("\n", 2);
		execve(cmd, all->n_av, environ);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

/*

ls -al | cat infile kasljdlasjd | grep hello

exeve -> argv -> [ls] [-al]

커맨드 에러처리(/bin/..가 같이 들어왔을때 join하면 안됨)
구조체 이름 pipe 바꾸기
argv 바꾸기(new_argv) : https://www.it-note.kr/157
fd 꼼꼼하게 닫기
echo $? : EXIT_STATUS확인하기
0777 -> 0644 : why??

ps : 프로세스 상태
lsof -p (pid) : 프로세스 fd확인


*/


int	main(int argc, char *argv[])
{
	t_pipex	all;
	int		i;
	char	*cmd;

	i = 1;
	get_path(&all);
	if (argc >= 5)
	{
		// if (ft_strnstr(argv[1], "here_doc", 8) == 0) //리턴값 확인해보기
		// {
		// 	all.hd = 1;
		// 	all.fd.out = open(argv[argc - 1], O_WRONLY | O_CREAT, 0644);
		// 	//heredoc
		// }
		// else
		// {
			all.hd = 0;
			all.fd.in = open(argv[1], O_RDONLY | O_CREAT, 0644);
			all.fd.out = open(argv[argc - 1], O_WRONLY | O_CREAT, 0644);
			dup2(all.fd.in, STDIN_FILENO);
		// }
		while (++i + all.hd < argc - 2)
		{
			get_av(&all, argv[i + all.hd]);
			cmd = get_cmd(all.n_av[0], all.list_path); //수정 필요
			piper(cmd, &all);
		}
		dup2(all.fd.out, STDOUT_FILENO);
		waitpid(0, NULL, 0);
		cmd = get_cmd(all.n_av[0], all.list_path);
		execve(cmd, all.n_av, environ);
	}
	err_msg_fd("arguments invalid", 2);
}
