/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:24:26 by vaferrei          #+#    #+#             */
/*   Updated: 2021/08/23 15:57:53 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int		i;
	const unsigned char	*s3;
	const unsigned char	*s4;

	s3 = (const unsigned char *)s1;
	s4 = (const unsigned char *)s2;
	i = 0;
	while (i < n && s3[i] && s4[i])
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
