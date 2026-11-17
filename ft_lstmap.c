/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sobueno <sobueno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 08:25:06 by sofiabuenos       #+#    #+#             */
/*   Updated: 2026/11/17 19:42:11 by sobueno          ###   ########.fr       */
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

/*void *ft_dotstr(char *str)
{
	int	i = 0;
	size_t len = ft_strlen(str) + 2;
	char *s;

	s = ft_calloc(len, sizeof(char));
	if (!s)
		return(NULL);
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '.';
	i++;
	s[i] = '\0';
	return(s);
}
int	main(void)
{
	t_list *head = NULL;
	t_list *headnova;
	
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("ana")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("bia")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("caetana")));
	
	t_list *current = head;
	while(current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	
	headnova = ft_lstmap(head, (void *)ft_dotstr, free);
	t_list *currentnovo = headnova;
	while(currentnovo)
	{
		printf("%s\n", (char *)currentnovo->content);
		currentnovo =  currentnovo->next;
	}
	ft_lstclear(&head, free);
	ft_lstclear(&headnova, free);
}*/