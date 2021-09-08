/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:23:38 by vaferrei          #+#    #+#             */
/*   Updated: 2021/09/07 12:08:01 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*cstr;
	unsigned char	cc;

	i = 0;
	cstr = (unsigned char *)str;
	cc = (unsigned char)c;
	while (i < n)
	{
		if (*cstr == cc)
			return (cstr);
		cstr++;
		i++;
	}
	return (NULL);
}
