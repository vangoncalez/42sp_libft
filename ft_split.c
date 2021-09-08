/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:24:01 by vaferrei          #+#    #+#             */
/*   Updated: 2021/09/07 15:41:53 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char const *str, char c)
{
	int		words;
	int		control;

	words = 0;
	control = 0;
	while (*str)
	{
		if (*str != c && control == 0)
		{
			control = 1;
			words++;
		}
		else if (*str == c)
			control = 0;
		str++;
	}
	return (words);
}

int	ft_wordsize(char const *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
		{
			return (i);
		}
		str++;
		i++;
	}
	return (i);
}

char	**ft_tosplit(char const *s, char **split, char c)
{
	int		len;
	int		control;
	int		i;
	int		j;

	i = 0;
	j = 0;
	control = 0;
	while (s[i])
	{
		if (s[i] != c && control == 0)
		{
			len = ft_wordsize(s + i, c);
			split[j] = (char *) ft_calloc (sizeof(char), (len + 1));
			if (split[j] != NULL)
				ft_strlcpy (split[j], s + i, len + 1);
			control = 1;
			j++;
		}
		else if (s[i] == c)
			control = 0;
		i++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;

	if (!s)
		return (0);
	words = ft_countwords(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (split == NULL)
		return (NULL);
	split = ft_tosplit (s, split, c);
	split[words] = NULL;
	return (split);
}
