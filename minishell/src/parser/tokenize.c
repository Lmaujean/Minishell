/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 07:34:17 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/18 09:56:09 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "nodes.h"
#include "parser.h"
#include "ft_string.h"

char	*trim_spaces(char *s);

static char	*split(t_node **list, char **str, char *start, char *cursor)
{
	node_add(list, node_new((void *) ft_strndup(start, (*str - start))));
	if (cursor)
	{
		if (is_op(*(++(*str))) && is_op(*(cursor + 1)))
			++(*str);
		node_add(list, node_new((void *) ft_strndup(cursor, (*str - cursor))));
	}
	return (*str);
}

static int	assign(int *p, int val)
{
	*p = val;
	return (1);
}

t_node	*tokenize(char *str, t_shell *shell)
{
	char const	*start = trim_spaces(str);
	char		*cursor;
	int			space;
	t_node		*list;

	list = 0;
	space = 1;
	while (*str)
	{
		cursor = str;
		if (*cursor == '\'' || *cursor == '"')
			str = ft_strchr((str + 1), *cursor);
		if (!str)
			return (0);
		if (is_op(*cursor) && assign(&space, 1))
			start = split(&list, &str, (char *) start, cursor);
		else if (*cursor == ' ' && space && assign(&space, 0))
			start = split(&list, &str, (char *) start, 0);
		else
			str++;
	}
	node_add(&list, node_new((void *) ft_strndup(start, str - start)));
	return (parse(list, shell));
}
