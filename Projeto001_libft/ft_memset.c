/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:23:48 by vaferrei          #+#    #+#             */
/*   Updated: 2021/08/20 09:26:05 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*newstr;

	newstr = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		newstr[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
