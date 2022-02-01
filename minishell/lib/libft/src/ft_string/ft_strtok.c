/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:20:47 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/05 11:59:26 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_stdlib.h"

#include <stdlib.h>
#include <string.h>

static int	ft_strcspn(char *str, char *set)
{
	char	c;
	char	*p;
	char	*s;

	s = str;
	c = *s;
	while (c)
	{
		p = set;
		while (*p)
		{
			if (c == *p++)
				return (s - str);
		}
		s++;
		c = *s;
	}
	return (s - str);
}

char	*ft_strtok(char *s, char const *delim)
{
	static char		*cursor;

	if (s == 0)
		s = cursor;
	if (*s == '\0')
		return (0);
	while (ft_strchr(delim, *s))
		if (*s++ == '\0')
			return (0);
	cursor = s + ft_strcspn(s, (char *) delim);
	if (*cursor != 0)
		*cursor++ = 0;
	return (s);
}
