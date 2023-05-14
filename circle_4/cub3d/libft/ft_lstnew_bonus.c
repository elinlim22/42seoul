/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:18:47 by dongyoki          #+#    #+#             */
/*   Updated: 2023/02/23 19:07:07 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *content, int y)
{
	t_list	*res;

	res = ft_malloc(sizeof(t_list));
	if (!res)
		return (0);
	res->str = content;
	res->x_size = ft_strlen(content);
	res->y_size = y;
	res->next = 0;
	return (res);
}
