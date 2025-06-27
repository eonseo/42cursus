/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerpark <yerpark@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:25:00 by yerpark           #+#    #+#             */
/*   Updated: 2024/03/31 17:02:27 by yerpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;

	newlist = NULL;
	while (lst != NULL)
	{
		newnode = ft_lstnew(f(lst -> content));
		if (!newnode)
			ft_lstclear(&newlist, del);
		ft_lstadd_back(&newlist, newnode);
		lst = lst -> next;
	}
	return (newlist);
}
