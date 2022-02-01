/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:23:11 by kjaoudi           #+#    #+#             */
/*   Updated: 2021/10/13 11:49:17 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_string.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	min_len;
	char	*ret;

	if (!s || len <= 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	else
	{
		min_len = ft_strlen(&s[start]);
		if (min_len < len)
			len = min_len;
		ret = malloc(sizeof(*ret) * (len + 1));
		if (!ret)
			return (NULL);
		i = start;
		while (s[i] && (i - start) < len)
		{
			ret[i - start] = s[i];
			i++;
		}
		ret[i - start] = '\0';
		return (ret);
	}
}
