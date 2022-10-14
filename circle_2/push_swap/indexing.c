/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:12:11 by hyeslim           #+#    #+#             */
/*   Updated: 2022/10/14 21:21:33 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int *arr = arg_parsing(argc, argv);

}
/* quick sort?
void	sorting(int *arr, int l, int r)
{
	int	pivot = arr[(sizeof(arr)/sizeof(int)) / 2];
	int	temp;
	int	left = arr[0];
	int	right = arr[sizeof(arr)/sizeof(int) - 1];

	while (left <= right)
	{
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left <= right)
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
	}
	if ()
}
*/
