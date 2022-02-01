/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_drop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:10:30 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/08 12:37:27 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_node.h"

#include <stdlib.h>

void	node_drop(t_node **head)
{
	t_node	*tmp;
	t_node	*it;

	if ((*head)->next == NULL)
	{
		free((*head)->data);
		(*head)->data = NULL;
		free(*head);
		head = NULL;
	}
	else
	{
		it = *head;
		while (it->next)
		{
			tmp = it;
			it = it->next;
		}
		free(tmp->next->data);
		tmp->next->data = NULL;
		free(tmp->next);
		tmp->next = NULL;
	}
}
