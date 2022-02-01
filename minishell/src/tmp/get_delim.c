/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_delim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:31:36 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/19 13:36:27 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

#include <stdio.h>
#include <readline/readline.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*expand_var(char *cmd, t_shell *shell);

char	*get_delim(char *delim, t_shell *shell)
{
	char		*ret;
	char		*line;

	ret = ft_strdup("");
	line = readline("> ");
	while (line)
	{
		if (diff(line, delim) == 0)
		{
			free(line);
			break ;
		}
		line = my_strjoin(line, "\n");
		ret = my_strjoin(ret, line);
		free(line);
		line = readline("> ");
		if (!line)
			printf("warning : EOL detected\n");
	}
	return (expand_var(ret, shell));
}
