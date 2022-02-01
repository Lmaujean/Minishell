/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:48:06 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/18 16:58:44 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_nonstd.h"

#include <stdlib.h>

char	*my_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	if (ret)
		if (s1)
			free((void *) s1);
	return (ret);
}
