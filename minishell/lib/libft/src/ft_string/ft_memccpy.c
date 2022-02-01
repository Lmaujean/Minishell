/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:25:18 by kjaoudi           #+#    #+#             */
/*   Updated: 2021/10/13 11:38:26 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*pt_dst;
	char	*pt_src;

	pt_dst = (char *)dst;
	pt_src = (char *)src;
	i = 0;
	while (i < n)
	{
		pt_dst[i] = pt_src[i];
		if (pt_dst[i] == (char)c)
			return ((void *)(dst + i + 1));
		++i;
	}
	return (NULL);
}
