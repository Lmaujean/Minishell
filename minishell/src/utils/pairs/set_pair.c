/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pair.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:36:49 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/13 15:22:53 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "utils.h"
#include "nodes.h"
#include "t_node.h"
#include "ft_string.h"

#include <stdlib.h>

int	set_pair(t_node **list, char const *find, char const *newval)
{
	t_pair			*pair;

	pair = get_pair(*list, find);
	if (pair)
	{
		free(pair->value);
		pair->value = ft_strdup(newval);
		return (1);
	}
	return (add_pair(list, find, newval));
}
