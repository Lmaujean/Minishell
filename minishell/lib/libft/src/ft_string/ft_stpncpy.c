/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 02:58:12 by kjaoudi           #+#    #+#             */
/*   Updated: 2021/10/13 11:39:45 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_stpncpy(char *dst, char const *src, size_t n)
{
	while (*src && n--)
		*dst++ = *src++;
	*dst = '\0';
	return (dst);
}
