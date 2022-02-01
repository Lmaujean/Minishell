/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 02:59:42 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/04 17:09:49 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_stdlib.h"

char	*ft_strndup(char const *str, size_t n)
{
	size_t const	len = ft_strnlen(str, n);
	char			*ret;

	ret = ft_calloc((1 + len), sizeof(*ret));
	if (ret)
		ft_memcpy(ret, str, len);
	return (ret);
}
