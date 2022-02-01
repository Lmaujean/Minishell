/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 07:33:39 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/18 10:29:37 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "types.h"
#include "utils.h"

#include <stdlib.h>
#include <unistd.h>

static char	*join(char **ret, char **cursor, char *cmd, t_shell *shell)
{
	t_pair	*pair;
	char	*find;

	*cmd++ = 0;
	find = ft_strndup(cmd, (var_end(cmd) - cmd));
	pair = get_pair((t_node *) shell->env, find);
	if (pair)
		*ret = my_strjoin(my_strjoin(*ret, *cursor), pair->value);
	else
	{
		pair = get_pair((t_node *) shell->var_list, find);
		if (pair)
			*ret = my_strjoin(my_strjoin(*ret, *cursor), pair->value);
		else
			*ret = my_strjoin(*ret, *cursor);
	}
	free(find);
	*cursor = var_end(cmd);
	return (*cursor);
}

static char	*find(char **ret, char **cursor, char **cmd, t_shell *shell)
{
	if (**cmd == '$')
		*cmd = join(ret, cursor, *cmd, shell);
	else
		(*cmd)++;
	return (*cmd);
}

char	*expand_var(char *cmd, t_shell *shell)
{
	char const	*freecmd = cmd;
	char const	*cursor = cmd;
	char		*stop;
	char		*ret;

	ret = ft_strdup("");
	while (*cmd)
	{
		if (*cmd == '"' || *cmd == '$')
		{
			stop = 1 + ft_strchr((cmd + 1), '"');
			if (*cmd == '$')
				stop = var_end(cmd + 1);
			while (cmd < stop)
				cmd = find(&ret, (char **) &cursor, &cmd, shell);
		}
		else if (*cmd == '\'')
			cmd = 1 + ft_strchr((cmd + 1), '\'');
		else
			cmd++;
	}
	ret = my_strjoin(ret, cursor);
	free((char *) freecmd);
	return (ret);
}
