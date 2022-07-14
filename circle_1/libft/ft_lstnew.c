/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:49:26 by hyeslim           #+#    #+#             */
/*   Updated: 2022/07/14 16:14:23 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list	*new;
	element = (t_list *)malloc(sizeof(t_list));
	if (!content)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}
