/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:23:36 by vaferrei          #+#    #+#             */
/*   Updated: 2021/08/26 17:31:26 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoains(long n, char *str, int *i)
{
	if (n > 9)
	{
		ft_itoains(n / 10, str, i);
		ft_itoains(n % 10, str, i);
	}
	else
		str[(*i)++] = n + '0';
}

static size_t	ft_itoalen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len = len + 1;
	while (n)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (ft_itoalen(n) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	if (n == -2147483648)
	{
		str[i++] = '-';
		str[i++] = '2';
		n = 147483648;
	}
	else if (n < 0)
	{
		str[i++] = '-';
		n *= -1;
	}
	ft_itoains(n, str, &i);
	str[i] = '\0';
	return (str);
}
