/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:23:40 by vaferrei          #+#    #+#             */
/*   Updated: 2021/08/28 17:21:22 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				i;
	const unsigned char	*s3;
	const unsigned char	*s4;

	s3 = (const unsigned char *)str1;
	s4 = (const unsigned char *)str2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s3[i] != s4[i])
			return (s3[i] - s4[i]);
		i++;
	}
	if (i < n && s4[i])
		return (0 - s4[i]);
	if (i < n && s3[i])
		return (s3[i]);
	return (0);
}
