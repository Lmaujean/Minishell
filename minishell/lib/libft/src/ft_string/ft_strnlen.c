/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:39:07 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/04 16:26:36 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_string.h"

size_t	ft_strnlen(char const *str, size_t maxlen)
{
	char	*p;

	p = ft_memchr(str, 0, maxlen);
	if (p == 0)
		return (maxlen);
	else
		return (p - str);
}
