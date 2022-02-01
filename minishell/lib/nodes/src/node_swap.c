/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:46:57 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/08 12:38:50 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_node.h"

void	node_swap(t_node **a, t_node **b)
{
	void	*tmp;

	if (*a && *b)
	{
		tmp = (*b)->data;
		(*b)->data = (*a)->data;
		(*a)->data = tmp;
	}
}
