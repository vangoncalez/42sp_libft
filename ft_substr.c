/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:24:37 by vaferrei          #+#    #+#             */
/*   Updated: 2021/09/07 13:36:23 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			totallen;

	if (s == NULL)
		return (NULL);
	totallen = ft_strlen(s);
	if (totallen < start)
		return (ft_strdup(""));
	totallen = ft_strlen(s + start);
	if (totallen < len)
		len = totallen;
	substr = (char *)malloc (sizeof(char) * len + 1);
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
