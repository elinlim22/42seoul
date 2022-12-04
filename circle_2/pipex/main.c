/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:50:47 by hyeslim           #+#    #+#             */
/*   Updated: 2022/12/04 21:41:08 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* 풀이 순서
	1. 받는 인자 체크
	2. pipe함수 예외처리
	3. fork 예외처리
		** fork : 새로운 자식 프로세스를 만듬
	4. pid를 활용하여 부모자식 분기 : 부모 프로세스에 waitpid 적용
	5. ...


	허용함수
	open : O_WRONLY | O_CREAT(파일이 없으면 접근권한을 지정해서 새롭게 생성) | mode(chomod할 때 그거)
	close
	read / write
	malloc / free
	perror / strerror
	access : 파일 권한 확인
	dup : object descriptor를 calling process에 복제하여 넘기고 새로운 파일 디스크립터 리턴 :  (fildes2 = dup(fildes))
	dup2 : fildes2가 specified(ex : dup2(infilefd, STDIN_FILENO))
	execve : calling process를 new process로 전환... 실행
	exit
	fork : 새로운 자식 프로세스를 만듬
	pipe
	unlink
	wait / waitpid


*/

int	opener(char *file, int status)
{
	int	fd;

	fd = 0;
	if (status == STDIN_FILENO)
		fd = open(file, O_RDONLY);
	else if (status == STDOUT_FILENO)
		fd = open(file, O_WRONLY | O_CREAT, 0777);
	else if (status == STDOUT_HD)
	{
		//here_doc일 때 처리
	}
	if (fd <= ERROR)
		err_msg_fd("fail to open", 2);
	return (fd);
}

void	piper(t_pipe *pipe, t_args *args)
{
	int	i;

	i = 2 + pipe->hd;
	while (i < args->argc - 2)
		forker(args->argv[i++], args->envp);
	dup2(pipe->fd_out, 1);
	//execve함수 자리
}

void	forker(char *argv, char **envp)
{
	int	fd[2];
	pid_t	pid;

	if (pipe(fd) == ERROR)
		err_msg_fd("pipe error", 2);
	pid = fork();
	if (pid == ERROR)
		err_msg_fd("fork error", 2);
	if (pid == CHILD) //자식 프로세스
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		//execve함수 자리
	}
	else
	{
		dup2(fd[0], STDIN_FILENO); //부모 프로세스
		close(fd[1]);
		waitpid(pid, NULL, 0);
		//execve함수 자리
	}
}

int	main(int argc, char *argv[], char **envp)
{
	t_pipe	pipe;
	t_args	args;

	args.argc = argc;
	args.argv = argv;
	args.envp = envp;
	if (argc < 2)
		err_msg("not enough arguments");
	else
	{
		if (!ft_strncmp(argv[1], "here_doc", 8))
		{
			pipe.hd = 1;
			//here_doc일땐 꺾쇠 두개 (>>, <<) 처리 : O_APPEND 사용해서 open
		}
		else
		{
			pipe.hd = 0;
			//here_doc 아닐 때 pipe처리
			pipe.fd_in = opener(argv[1], STDIN_FILENO);
			pipe.fd_out = opener(argv[argc - 1], STDOUT_FILENO);
			dup2(pipe.fd_in, 0);
		}
		piper(&pipe, &args);
	}
	exit(0);
}
