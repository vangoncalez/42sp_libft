/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:23:38 by vaferrei          #+#    #+#             */
/*   Updated: 2021/09/01 22:56:05 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	char	*cstr;

	i = 0;
	cstr = (char *)str;
	while (cstr[i] && i < n)
	{
		if (cstr[i] == c)
			return ((char *)cstr + i);
		i++;
	}
	if (c == '\0' && cstr[i] == '\0')
		return ((char *)cstr + i);
	return (NULL);
}
