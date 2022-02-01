/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:24:20 by kjaoudi           #+#    #+#             */
/*   Updated: 2021/10/13 11:36:44 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	neg;

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
