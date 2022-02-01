/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:12:30 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/08 12:37:52 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_node.h"

#include <stddef.h>

t_node	*node_iter(t_node *head, size_t n)
{
	if (n != 1)
	{
		while (head && n--)
			head = head->next;
	}
	return (head);
}
