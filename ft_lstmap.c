/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabuenos <sofiabuenos@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 08:25:06 by sofiabuenos       #+#    #+#             */
/*   Updated: 2026/11/12 09:56:17 by sofiabuenos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	alloc_failed(void *content, t_list **head, void (*del)(void *))
{
	del(content);
	ft_lstclear(head, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;
	void	*content;

	if (!lst || !f)
		return (NULL);
	head = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		tmp = ft_lstnew(content);
		if (!tmp)
		{
			alloc_failed(content, &head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, tmp);
		lst = lst->next;
	}
	return (head);
}
