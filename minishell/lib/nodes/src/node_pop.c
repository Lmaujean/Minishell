/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:34:13 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/08 12:38:33 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_node.h"

#include <stdlib.h>

void	node_pop(t_node **n)
{
	t_node	*tmp;

	tmp = NULL;
	if (*n)
	{
		if ((*n)->next)
			tmp = (*n)->next;
		free((*n)->data);
		(*n)->data = NULL;
		free(*n);
		*n = tmp;
	}
}
