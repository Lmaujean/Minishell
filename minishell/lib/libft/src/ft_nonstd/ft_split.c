/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:22:50 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/07 12:10:55 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_stdlib.h"
#include "ft_nonstd.h"

#include <stdlib.h>

static char	*skip(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *) s);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (!(*s))
		return (0);
	s = skip(s, c);
	while (*s)
	{
		if (*s == c)
		{
			count++;
			s = skip(s, c);
			continue ;
		}
		s++;
	}
	if (*(s - 1) != c)
		count++;
	return (count);
}

static char	**join_words(char **ret, char *s, char c)
{
	char const	*dup = ft_strdup(s);
	char		**it;
	char		*tmp;
	char		*tok;
	char		d[2];

	it = ret;
	d[0] = c;
	d[1] = 0;
	tmp = (char *) dup;
	tok = ft_strtok((char *) dup, d);
	while (tok)
	{
		*it++ = ft_strdup(tok);
		tok = ft_strtok(NULL, d);
	}
	free(tmp);
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	size_t const	count = count_words((char *) s, c);
	char			**ret;

	ret = 0;
	if (s)
	{
		ret = ft_calloc(1 + count, sizeof(*ret));
		if (ret)
			ret = join_words(ret, (char *) s, c);
		else
			free_split(ret);
	}
	return (ret);
}
