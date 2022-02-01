/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:18:33 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/19 11:22:14 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*ret;
	char	*tmp;

	ret = 0;
	if (!n)
		return (ft_strdup(s1));
	ret = ft_calloc((1 + ft_strlen(s1) + n), sizeof(*ret));
	tmp = ret;
	if (ret)
		ft_stpncpy(ft_stpcpy(tmp, s1), s2, n);
	return (ret);
}
