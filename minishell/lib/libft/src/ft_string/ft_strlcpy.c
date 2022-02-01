/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:23:00 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/07 12:32:07 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_strlcpy(char *dst, char const *src, size_t len)
{
	const size_t	srclen = ft_strlen(src);

	if (srclen < len)
	{
		ft_memcpy(dst, src, srclen + 1);
	}
	else if (len != 0)
	{
		ft_memcpy(dst, src, len - 1);
		dst[len - 1] = '\0';
	}
	return (srclen);
}
