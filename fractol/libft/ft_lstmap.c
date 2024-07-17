/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirotsu <ahirotsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:28:18 by ahirotsu          #+#    #+#             */
/*   Updated: 2023/09/28 22:15:24 by ahirotsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*a;
	t_list	*b;

	if (lst == NULL || f == NULL)
		return (NULL);
	a = NULL;
	while (lst != NULL)
	{
		b = ft_lstnew(f(lst->content));
		if (b == NULL)
		{
			if (del != NULL)
				ft_lstclear(&a, del);
			return (a);
		}
		ft_lstadd_back(&a, b);
		lst = lst->next;
	}
	return (a);
}
