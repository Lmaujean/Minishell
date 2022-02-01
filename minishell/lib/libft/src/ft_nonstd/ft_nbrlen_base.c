/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 09:56:12 by kjaoudi           #+#    #+#             */
/*   Updated: 2021/10/13 11:51:00 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_nbrlen_base(long long n, int base)
{
	size_t	count;

	count = 1;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	if (n >= (long long)base)
		count += ft_nbrlen_base(n / base, base);
	return (count);
}
