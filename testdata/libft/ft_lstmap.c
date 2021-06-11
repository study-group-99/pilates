/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchristo <bchristo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:42:18 by bchristo          #+#    #+#             */
/*   Updated: 2021/06/09 18:55:59 by bchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*r;
	t_list	*t;

	r = 0;
	while (lst)
	{
		t = ft_lstnew(f(lst->content));
		if (!t)
		{
			ft_lstclear(&r, del);
			return (0);
		}
		ft_lstadd_back(&r, t);
		lst = lst->next;
	}
	return (r);
}
