/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:15:29 by hyeslim           #+#    #+#             */
/*   Updated: 2022/10/05 21:46:34 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/* 인자 파싱하기 */
int	main(int argc, char *argv[])
{
	char	*str;
	int		i;
	int		j;
	char	**res;
	int		*arr;

	i = 1;
	str = ft_strdup("");
	// res = (char *)malloc(sizeof(char *) * (argc));
	// if (argc < 3) //숫자 여러개가 하나의 인자로 들어올 경우는..?
	// 	exit(0);
	while (i < argc)
	{
		str = ft_strjoin(str, argv[i++]); //str를 temp에??
		str = ft_strjoin(str, " ");
	}
	printf("str is %s\n", str);
	res = ft_split(str, ' '); //free 잊지말기
	i = 0;
	j = 0;
	/* 검사 1 */
	while (res[i])
	{
		while (res[i][j])
		{
			if (!ft_isdigit(res[i][j]))
				exit(write(1, "Error\n", 6));
			else
				j++;
		}
		i++;
	}
	/* ft_atoi */
	i = 0;
	arr = (int *)malloc(sizeof(int) * (argc - 1));
	while (res[i])
	{
		arr[i] = ft_atoi(res[i]);
		i++;
	}
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
	while (arr[i + 1])
	{
		if (arr[i] < arr[i + 1])
			i++;
		else
			break ;
		if (!arr[i + 1])
			exit(write(1, "sorted\n", 7)); //정렬 확인됨
	}
	free(res); //free위치 고려하기
	free(str); //얘도
	return (write(1, "done\n", 5));
}


/* 전처리
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
		'4개일때 -> 3개 솔팅함수로 빠진다
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
