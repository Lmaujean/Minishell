/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:25:41 by kjaoudi           #+#    #+#             */
/*   Updated: 2021/10/13 11:39:39 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_stpcpy(char *dst, char const *src)
{
	size_t const	len = ft_strlen(src);

	return (len + ft_memcpy(dst, src, len + 1));
}
