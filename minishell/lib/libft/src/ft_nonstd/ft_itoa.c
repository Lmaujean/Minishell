/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:22:44 by kjaoudi           #+#    #+#             */
/*   Updated: 2021/10/13 11:45:23 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_nbdigits(unsigned int n);

char	*ft_itoa(int n)
{
	char			*str;
	int				size;
	int				neg;
	unsigned int	nb;

	neg = 0;
	nb = n;
	if (n < 0 && ++neg)
		nb = -n;
	size = ft_nbdigits(nb) + neg;
	str = malloc(size + 1);
	if (!str)
		return (0);
	str[size] = 0;
	while (size--)
	{
		str[size] = nb % 10 + '0';
		nb /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

static int	ft_nbdigits(unsigned int n)
{
	int	size;

	size = 1;
	while (n > 9)
	{
		n /= 10;
		size++;
	}
	return (size);
}
