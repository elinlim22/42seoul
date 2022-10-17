/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:24:05 by hyeslim           #+#    #+#             */
/*   Updated: 2022/10/17 15:56:47 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
			if (!ft_isdigit(res[i][j])) //숫자가 맞는지 확인
				return (0); //아니면 0리턴 -> Error 출력
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

int	*do_atoi(char **res, int count) //array 길이 반환
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * count);
	while (res[i])
	{
		arr[i] = ft_atoi(res[i]);
		i++;
	}
	return (arr);
}

int	check_second(int *arr) //중복검사
{
	int	i;
	int	j;

	i = 0;
	while (arr[i + 1])
	{
		j = i + 1;
		while (arr[j])
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

int	check_sorted(int *arr, int count)
{
	int	i;

	i = 0;
	while (i < count - 1) //이미 정렬인지 확인
	{
		if (arr[i] < arr[i + 1])
		{
			i++;
			if (i + 1 == count)
				return (0); // 모두 정렬이면 리턴0
				// exit(0);
		}
		else
			break ;
	}
	printf("정렬 안됨\n");
	return (1);
}

void	free_all(char **res, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		printf("freeing cell no.%d : %s\n", i, res[i]);
		free(res[i++]);
	}
	free(res);
}

int	count_args(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		i++;
	printf("count_args : %d\n", i);
	return (i);
}

int main(int argc, char *argv[])
{
	char **res = set_str(argc, argv);
	int i = count_args(res);

	if (check_first(res)) //충분한 숫자인자?
	{
		printf("숫자 맞고 개수 충분\n");
		int *arr = do_atoi(res, i);

		if (!check_second(arr) || !check_sorted(arr, i))
		{
			printf("Error\n");
			free_all(res, i);
			free(arr);
			system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
			return (0);
		}
		else
		{
			printf("OK\n");
			free_all(res, i);
			free(arr);
		}
	}
	else
	{
		printf("Ko\n");
		free_all(res, i);
	}
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}