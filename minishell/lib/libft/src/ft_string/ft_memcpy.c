/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:25:30 by kjaoudi           #+#    #+#             */
/*   Updated: 2021/10/13 11:39:13 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char		*pt_dst;
	char const	*pt_src = (char *) src;

	pt_dst = (char *)dst;
	while (len--)
		*pt_dst++ = *pt_src++;
	return (dst);
}
