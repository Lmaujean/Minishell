/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_binpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:47:18 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/19 13:39:40 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_nonstd.h"
#include "ft_string.h"
#include "types.h"

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

static int	check_permissions(char const *filepath)
{
	struct stat	filestat;

	if (stat(filepath, &filestat) == 0)
	{
		if ((filestat.st_mode & S_IXUSR)
			&& (filestat.st_mode & S_IXGRP)
			&& (filestat.st_mode & S_IXOTH))
		{
			return (1);
		}
	}
	return (0);
}

char	*get_binpath(char const *find, t_shell *shell)
{
	char			**split;
	char			**tmp;
	char			*ret;
	t_pair const	*path = get_pair(shell->env, "PATH");

	if (check_permissions(find))
		return (ft_strdup(find));
	ret = NULL;
	if (!path)
		return (ret);
	split = ft_split((char *)path->value, ':');
	tmp = split;
	while (tmp && *tmp)
	{
		*tmp = my_strjoin(*tmp, "/");
		*tmp = my_strjoin(*tmp, find);
		if (check_permissions(*tmp))
		{
			ret = ft_strdup(*tmp);
			break ;
		}
		tmp++;
	}
	free_split(split);
	return (ret);
}
