/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:24:01 by vaferrei          #+#    #+#             */
/*   Updated: 2021/08/26 22:12:24 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_splitparts(char const *trimmed, char c)
{
	int		i;
	int		count;
	int		control;

	i = 0;
	count = 0;
	control = 0;
	while (trimmed[i])
	{
		if (trimmed[i] != c)
			control = 0;
		else
		{
			if (control == 0)
			{
				count++;
				control = 1;
			}
		}
		i++;
	}
	return (count);
}

int	ft_splitwlen(char const *trimmed, char c, int index)
{
	int	j;
	int	count;
	int	countindex;
	int	control1;

	j = 0;
	count = 0;
	control1 = 0;
	countindex = -1;
	while (trimmed[j])
	{
		if (trimmed[j] != c)
		{
			if (control1 == 0)
			{
				countindex++;
				control1 = 1;
			}
			count++;
		}
		else
		{
			if (index == countindex)
				break ;
			control1 = 0;
			count = 0;
		}
		j++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*trimmed;
	int		i;
	int		j;
	int		k;
	int		count;
	int		control;

	trimmed = ft_strtrim(s, &c);
	count = ft_splitparts(trimmed, c);
	i = 0;
	split = (char **)ft_calloc(count + 1, sizeof(char *));
	if (split == NULL)
		return (NULL);
	while (i < count + 1)
	{
		split[i] = (char *)ft_calloc (ft_splitwlen(trimmed, c, i) + 1, sizeof   	(char));
		i++;
	}
	i = 0;
	j = 0;
	k = 0;
	control = 0;
	while (trimmed[i])
	{
		if (trimmed[i] != c)
		{
			split[j][k] = trimmed[i];
			control = 0;
			k++;
		}
		else
		{
			if (control == 0)
			{
				split[j][k] = '\0';
				j++;
				k = 0;
				control = 1;
			}
		}
		i++;
	}
	if (ft_strlen(s) == 0)
		split[i] = NULL;
	return (split);
}
