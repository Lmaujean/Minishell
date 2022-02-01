/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 07:34:30 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/08 12:48:04 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_node.h"

#include <stdio.h>

void	print_nodes(t_node *n)
{
	while (n)
	{
		printf("[%s]", (char *) n->data);
		n = n->next;
	}
	puts("");
}
