/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:24:05 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/13 15:47:23 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_first(char **res);
int		*do_atoi(char **res, int size);
int		check_second(int *arr, int size);
int		check_sorted(int *arr, int size);

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
			if (!ft_isdigit(res[i][j]) &&
				j != 0 && res[i][j] == '-') //숫자가 맞는지 확인
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

int	*do_atoi(char **res, int count)
{
	int		*arr;
	int		i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * count);
	if (!arr)
		return (0);
	while (res[i])
	{
		arr[i] = ft_atoi(res[i]);
		i++;
	}
	return (arr);
}

int	check_second(int *arr, int count) //중복검사
{
	int	i;
	int	j;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (arr[i] == arr[j])
				return (0); //Error 출력
			j++;
		}
		i++;
	}
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
	return (1);
}
