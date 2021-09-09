/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:34:02 by vaferrei          #+#    #+#             */
/*   Updated: 2021/09/09 12:37:44 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	new = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		temp = ft_lstnew(f(lst -> content));
		if (temp == NULL)
			ft_lstclear(&temp, del);
		lst = lst -> next;
		ft_lstadd_back(&new, temp);
	}
	return (new);
}
