/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:22:53 by kjaoudi           #+#    #+#             */
/*   Updated: 2021/10/13 11:47:40 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ret;
	char			*tmp;
	size_t const	len = 1 + ft_strlen(s1) + ft_strlen(s2);

	ret = ft_calloc(len, sizeof(*ret));
	tmp = ret;
	if (ret)
		ft_stpncpy(ft_stpcpy(tmp, s1), s2, len);
	return (ret);
}
