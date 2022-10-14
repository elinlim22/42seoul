/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:15:29 by hyeslim           #+#    #+#             */
/*   Updated: 2022/10/14 21:43:51 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/* 인자 파싱하기
	exit문 중 Error 제외하고 0으로 바꾸기
	리턴값 고려하기
	main이름 바꾸기-> 함수로 사용
	함수 나누기
*/
int	*arg_parsing(int argc, char *argv[])
{
	char	*str;
	int		i;
	int		j;
	char	**res;
	int		*arr;

	i = 1;
	/* 전처리 */
	str = ft_strdup("");
	if (argc < 2)
		exit(0);
	while (i < argc)
	{
		if (*(argv[i]) == '\0')
			exit(write(1, "Error\n", 6));
		str = ft_strjoin(str, argv[i++]);
		str = ft_strjoin(str, " ");
	}
	res = ft_split(str, ' ');
	i = 0;
	j = 0;
	/* 검사 1 */
	while (res[i])
	{
		while (res[i][j])
		{
			if (!ft_isdigit(res[i][j]))
				exit(0);
			else
				j++;
		}
		i++;
	}
	if (i < 2 && res[0] != NULL)
		exit(0);
	/* ft_atoi */
	i = 0;
	arr = (int *)malloc(sizeof(int) * (argc - 1));
	while (res[i])
	{
		arr[i] = ft_atoi(res[i]);
		i++;
	}
	int count = i;
	/* 검사 2 */
	i = 0;
	while (arr[i + 1])
	{
		j = i + 1;
		while (arr[j])
		{
			if (arr[i] == arr[j])
				exit(write(1, "Error\n", 6));
			j++;
		}
		i++;
	}
	i = 0;
	while (i < count - 1)
	{
		if (arr[i] < arr[i + 1])
		{
			i++;
			if (i + 1 == count)
				exit(0);
		}
		else
			break ;
	}
	free(res);
	free(str);
	return (arr);
}


/* 전처리 ::: 끝!
	1. 인자값이 정수가 아닐때
	2. 인자값이 정수보다 클때
	3. 중복된 인자가 있을때
	4. 인자가 없을때
	5. 인자가 1개이거나 이미 정렬되었을때는 종료
*/

/* 인자 받아와서 인덱싱 처리 */

/* 양방향 연결리스트 사용
	스택 A와 스택 B를 각각 구조체로 만들어서 left/right 이동이 가능하도록 설계()
	각 스택에서 up/down으로 이동이 가능하도록 설계
	각 인자마다 인덱스값을 넣을 int
*/

/* 함수 리스트
	1. 명령어 함수
*/

/*
	인자 전처리&인덱싱하기
		복사본을 만들고 원본과 대조하면서 원본에 인덱싱 처리를 한다
	5개 미만일때 정렬
		5개일 때 -> 4개 솔팅 함수로 빠진다
		4개일때 -> 3개 솔팅함수로 빠진다
		3개일때 하드코딩
		재귀로 복귀하면서
	make b
		모래시계 모양으로 만든다
			가장 작은값을 먼저 넘긴다
	find max
		가장 큰 값을 찾아서 에이로 넘긴다
		i++;
	move to a
	명령어 출력
*/
