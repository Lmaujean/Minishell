/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:03:56 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/04 17:09:32 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_stdlib.h"

char	*ft_strdup(char const *str)
{
	size_t const	len = ft_strlen(str);
	char			*ret;

	ret = ft_calloc((1 + len), sizeof(*ret));
	if (ret)
		ft_memcpy(ret, str, len);
	return (ret);
}
