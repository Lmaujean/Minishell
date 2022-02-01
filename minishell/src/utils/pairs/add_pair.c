/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pair.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:07:34 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/11 18:03:28 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nodes.h"
#include "types.h"
#include "t_node.h"
#include "ft_stdlib.h"
#include "ft_string.h"

int	add_pair(t_node **list, char const *newvar, char const *newval)
{
	t_pair	*pair;

	pair = ft_calloc(1, sizeof(*pair));
	if (pair)
	{
		pair->name = ft_strdup(newvar);
		pair->value = ft_strdup(newval);
		node_add(list, node_new((void *) pair));
		return (1);
	}
	return (0);
}
