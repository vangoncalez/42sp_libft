/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:34:02 by vaferrei          #+#    #+#             */
/*   Updated: 2021/08/26 22:37:01 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*temp;

// 	if(f && lst)
// 	{
// 		while (lst)
// 		{
// 			temp = f(lst);
// 			lst = lst->next;
// 		}
// 	}
// 	return (temp);
// }


// t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// 	t_list *new;
// 	t_list *curr;
// 	t_list *temp;

// 	if (!lst || !f)
// 		return (NULL);
// 	if (!(new_list = ft_lstnew(f(lst->content))))
// 		return (NULL);
// 	curr = new_list;
// 	lst = lst->next;
// 	while (lst)
// 	{
// 		if (!(temp = ft_lstnew(f(lst->content))))
// 		{
// 			ft_lstclear(&newlst, del);
// 			return (NULL);
// 		}
// 		curr->next = temp;
// 		curr = temp;
// 		lst = lst->next;
// 	}
// 	return (new_list);
// }
