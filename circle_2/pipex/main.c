/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:50:47 by hyeslim           #+#    #+#             */
/*   Updated: 2022/12/03 20:45:11 by hyeslim          ###   ########.fr       */
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
	open / close
	read / write
	malloc / free
	perror / strerror
	access : 파일 권한 확인
	dup : object descriptor를 calling process에 복제하여 넘기고 새로운 파일 디스크립터 리턴 :  (fildes2 = dup(fildes))
	dup2 : fildes2가 specified
	execve : calling process를 new process로 전환
	exit
	fork : 새로운 자식 프로세스를 만듬
	pipe
	unlink
	wait / waitpid


*/

// int	main(int argc, char *argv[], char **envp)
// {
// 	if (argc < 2)
// 		return (0);
// 	else
// 	{
// 		if (ft_strncmp(argv[1], "here_doc", 8))
// 			//here_doc일땐 꺾쇠 두개 (>>, <<) 처리
// 		else
// 		{}
// 	}
// }
