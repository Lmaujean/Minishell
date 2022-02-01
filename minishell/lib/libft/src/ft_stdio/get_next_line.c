/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:23:29 by kjaoudi           #+#    #+#             */
/*   Updated: 2021/10/16 07:30:19 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "ft_string.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

static char	*newstr(void);
static char	*my_strchr(char *s, char c);
static char	*my_strjoin(char *dst, char const *src);

char	*get_next_line(int const fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*found;
	size_t		bytes;

	bytes = BUFFER_SIZE;
	line = newstr();
	while (BUFFER_SIZE > 0 && line && !read(fd, buf[fd], 0))
	{
		found = my_strchr(buf[fd], '\n');
		line = my_strjoin(line, buf[fd]);
		if (found)
		{
			ft_stpcpy(buf[fd], found);
			return (my_strjoin(line, "\n"));
		}
		ft_bzero(buf[fd], BUFFER_SIZE);
		if (bytes != BUFFER_SIZE)
			return (line);
		bytes = read(fd, buf[fd], BUFFER_SIZE);
		if (bytes < 1 && !(*line))
			break ;
	}
	free(line);
	return (NULL);
}

static char	*newstr(void)
{
	char	*ret;

	ret = malloc(1);
	*ret = '\0';
	return (ret);
}

static char	*my_strchr(char *s, char c)
{
	while (*s != c)
		if (*s++ == '\0')
			return (NULL);
	*s++ = '\0';
	return (s);
}

static char	*my_strjoin(char *dst, char const *src)
{
	char	*ret;
	char	*tmp;

	ret = malloc(sizeof(*ret) * (1 + ft_strlen(dst) + ft_strlen(src)));
	tmp = ret;
	if (ret)
	{
		ft_stpcpy(ft_stpcpy(tmp, dst), src);
		free(dst);
		dst = NULL;
	}
	return (ret);
}
