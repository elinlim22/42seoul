/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db_lstclear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:44:43 by hyeslim           #+#    #+#             */
/*   Updated: 2022/10/23 20:47:30 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_db_lstclear(t_node **head)
{
	t_node	*temp;

	if (!*head || !head)
		return ;
	while (*head)
	{
		temp = (*head)->next;
		free((*head)->data);
		free(*head);
		*head = temp;
	}
	*head = NULL;
}
