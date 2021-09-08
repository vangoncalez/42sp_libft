/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:24:34 by vaferrei          #+#    #+#             */
/*   Updated: 2021/09/07 14:28:54 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strtrim_start(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	find;

	i = 0;
	while (s1[i])
	{
		j = 0;
		find = 0;
		while (set[j])
		{
			if (set[j] == s1[i])
				find++;
			j++;
		}
		if (find == 0)
			break ;
		i++;
	}
	return (i);
}

int	ft_strtrim_end(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	find;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		j = 0;
		find = 0;
		while (set[j])
		{
			if (set[j] == s1[i])
				find++;
			j++;
		}
		if (find == 0)
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = ft_strtrim_start(s1, set);
	end = 1 + ft_strtrim_end(s1, set);
	if (end <= start)
		return ((ft_strdup("")));
	str = (char *)malloc (sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);
}
