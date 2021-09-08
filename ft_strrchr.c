/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:24:31 by vaferrei          #+#    #+#             */
/*   Updated: 2021/09/07 12:58:19 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*cstr;
	int		len;
	char	cc;

	cstr = (char *)str;
	cc = (char)c;
	len = ft_strlen(cstr);
	if (cc == '\0')
		return ((char *)cstr + len);
	while (len >= 0)
	{
		if (cstr[len] == cc)
			return ((char *)cstr + len);
		len--;
	}
	return (NULL);
}
