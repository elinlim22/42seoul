/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db_lstadd_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:50:51 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/03 16:28:52 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_db_lstadd_back(t_node **where, t_node *new)
{
	t_node	*curr;

	curr = *where;
	if (*where == NULL)
		*where = new;
	else if ((*where)->type != 2) //머리에 붙이기
	{
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new;
		new->prev = curr;
	}
	else //꼬리에 붙이기
	{
		curr->prev->next = new;
		new->prev = curr->prev;
		new->next = curr;
		curr->prev = new;
	}
}
