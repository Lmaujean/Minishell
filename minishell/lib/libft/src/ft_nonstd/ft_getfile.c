/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:16:05 by kjaoudi           #+#    #+#             */
/*   Updated: 2021/10/13 11:50:49 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "ft_nonstd.h"
#include "ft_string.h"
#include "ft_stdio.h"

char	*ft_getfile(char const *path)
{
	int		fd;
	char	*line;
	char	*ret;
	char	*tmp;

	fd = open(path, O_RDONLY);
	if (read(fd, NULL, 0) == 0)
	{
		ret = ft_strdup("");
		line = get_next_line(fd);
		while (line)
		{
			tmp = ft_strdup(ret);
			free(ret);
			ret = ft_strjoin(tmp, line);
			free(tmp);
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
		return (ret);
	}
	return (NULL);
}
