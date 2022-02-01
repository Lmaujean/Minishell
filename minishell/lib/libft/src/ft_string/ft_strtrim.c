/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:48:58 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/19 10:56:13 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	char	*ret;
	char	*tmp;
	char	*end;

	while (*str && ft_strchr(set, *str))
		str++;
	end = ft_strrchr(str, 0);
	while (end > str && ft_strchr(set, *(end - 1)))
		end--;
	ret = ft_calloc(1 + (end - str), sizeof(*str));
	tmp = ret;
	if (ret)
		while (str < end)
			*tmp++ = *str++;
	return (ret);
}
