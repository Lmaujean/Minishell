/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:25:25 by kjaoudi           #+#    #+#             */
/*   Updated: 2021/10/13 11:38:47 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*pt_s1;
	unsigned char	*pt_s2;

	pt_s1 = (unsigned char *) s1;
	pt_s2 = (unsigned char *) s2;
	while (n--)
	{
		if (*pt_s1 != *pt_s2)
			return (*pt_s1 - *pt_s2);
		if (n)
		{
			pt_s1++;
			pt_s2++;
		}
	}
	return (0);
}
