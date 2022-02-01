/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pairval.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:09:06 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/11 12:54:24 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "utils.h"
#include "t_node.h"

t_pair	*get_pair(t_node *list, char const *find)
{
	t_pair			*pair;

	while (list)
	{
		pair = (t_pair *) list->data;
		if (!diff(pair->name, find))
			return (pair);
		list = list->next;
	}
	return (0);
}
