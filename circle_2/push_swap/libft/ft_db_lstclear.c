/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db_lstclear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:44:43 by hyeslim           #+#    #+#             */
/*   Updated: 2022/10/24 16:05:46 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_db_lstclear(t_node **head)
{
	t_node	*temp;

	if (!*head || !head)
		return ;
	while (*head)
	{
		printf("freeing %p...\n", *head);
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
	*head = NULL;
}
