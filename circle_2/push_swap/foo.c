/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:24:05 by hyeslim           #+#    #+#             */
/*   Updated: 2022/10/20 15:01:43 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //삭제
/* t_initial 사용 고려 */

/* 전처리 */
char	**set_str(int argc, char *argv[])
{
	char	*str;
	char	**res;
	int		i;
	char	*temp;

	i = 1;
	str = ft_strdup("");
	if (argc < 2)
		exit (0);
	while (i < argc)
	{
		if (*(argv[i]) == '\0')
			exit(write(1, "Error\n", 6));
		temp = str;
		str = ft_strjoin(temp, argv[i++]);
		free(temp);
		temp = str;
		str = ft_strjoin(temp, " ");
		free(temp);
	}
	res = ft_split(str, ' ');
	free(str);
	return (res);
}

int	check_first(char **res)
{
	int	i;
	int	j;

	i = 0;
	while (res[i])
	{
		j = 0;
		while (res[i][j])
		{
			if (!ft_isdigit(res[i][j]) && j != 0 && res[i][j] == '-') //숫자가 맞는지 확인
				return (0);//아니면 0리턴 -> Error 출력
				// exit(0);
			else
				j++;
		}
		i++;
	}
	if (i < 2 && res[0] != NULL) //나눈 뒤 인자의 개수가 적을때
		exit(0);
	return (1);
}

t_data	*do_atoi(char **res, int size) //array 길이 반환
{
	int		*arr;
	int		i;
	t_data	*data;

	i = 0;
	// arr = (int *)malloc(sizeof(int) * size);
	// if (!arr)
		// return (0);
	while (res[i])
	{
		data[i].num = ft_atoi(res[i]);
		data[i].flag = 1;
		i++;
	}
	return (data);
}

int	check_second(int *arr, int size) //중복검사
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (0); //Error 출력
			j++;
		}
		i++;
	}
	printf("중복 없음\n");
	return (1);
}

int	check_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1) //이미 정렬인지 확인
	{
		if (arr[i] < arr[i + 1])
		{
			i++;
			if (i + 1 == size)
				return (0); // 모두 정렬이면 리턴0
				// exit(0);
		}
		else
			break ;
	}
	printf("정렬 안됨\n");
	return (1);
}

void	free_all(char **res, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("freeing cell no.%d : %s\n", i, res[i]);
		free(res[i++]);
	}
	free(res);
}

int	size_args(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		i++;
	printf("size_args : %d\n", i);
	return (i);
}

t_stack	setup(char **res, int *arr, int size) ///목적 : main의 역할을 할 setup.. check역할 필요
{
	t_stack	set;

	if (check_first(res))
	{
		set.stack = do_atoi(res, size); //?????
		set.count = size_args(res);
		if (!check_second(set.stack, set.count) || !check_sorted(set.stack, set.count))
		{

		}
	}

	return (set);
}

// int main(int argc, char *argv[])
// {
// 	char **res = set_str(argc, argv);
// 	int i = size_args(res);

// 	if (check_first(res)) //충분한 숫자인자?
// 	{
// 		printf("숫자 맞고 개수 충분\n");
// 		int *arr = do_atoi(res, i);
// 		for (int j = 0; j < i; j++)
// 		{ printf("%3d", arr[j]); printf("\n");}

// 		if (!check_second(arr, i) || !check_sorted(arr, i)) //중복, 정렬검사
// 		{
// 			printf("Error\n");
// 			free_all(res, i);
// 			free(arr);
// 			system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
// 			return (0);
// 		}
// 		else
// 		{
// 			printf("OK\n");
// 			free_all(res, i);
// 			free(arr);
// 		}
// 	}
// 	else
// 	{
// 		printf("Ko : 숫자가 아니거나 인자의 개수가 부족\n");
// 		free_all(res, i);
// 	}
// 	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
// 	return (0);
// }
