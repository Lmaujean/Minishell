/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 08:02:00 by kjaoudi           #+#    #+#             */
/*   Updated: 2021/10/20 08:02:12 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

long	ft_atol(const char *str)
{
	long	res;
	int		neg;

	res = 0;
	neg = 1;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (ft_isdigit(*str) && *str)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * neg);
}
