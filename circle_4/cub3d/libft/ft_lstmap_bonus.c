/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:27:43 by dongyoki          #+#    #+#             */
/*   Updated: 2023/02/23 19:13:12 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		i;
	t_list	*res;
	t_list	*tmp;
	void	*tmp_c;

	res = 0;
	i = 0;
	while (lst)
	{
		tmp_c = f(lst->str);
		tmp = ft_lstnew(tmp_c, i);
		if (!tmp)
		{
			ft_lstclear(&res, del);
			del(tmp_c);
			break ;
		}
		ft_lstadd_back(&res, tmp);
		lst = lst->next;
	}
	return (res);
}
