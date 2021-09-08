/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:24:04 by vaferrei          #+#    #+#             */
/*   Updated: 2021/09/07 12:19:58 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char			*cstr;
	unsigned char	cc;

	cstr = (char *)str;
	cc = (unsigned char)c;
	while (*cstr)
	{
		if (*cstr == cc)
			return (cstr);
		cstr++;
	}
	if (cc == '\0' && *cstr == '\0')
		return (cstr);
	return (NULL);
}
