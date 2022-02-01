/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:23:05 by kjaoudi           #+#    #+#             */
/*   Updated: 2021/10/13 11:42:40 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_string.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t len)
{
	size_t	needle_len;

	if (*needle == '\0')
		return ((char *) haystack);
	needle_len = ft_strlen(needle);
	while (*haystack != '\0' && len-- >= needle_len)
	{
		if (*haystack == *needle
			&& ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *) haystack);
		haystack++;
	}
	return (NULL);
}
