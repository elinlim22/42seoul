/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:31:26 by hyeslim           #+#    #+#             */
/*   Updated: 2022/07/18 15:49:27 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!*lst || !del || !lst)
		return ;
	while ((*lst)->next)
	{
		ft_lstdelone(*lst, del);
		lst = NULL;
	}
}
