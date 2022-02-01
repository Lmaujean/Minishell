/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pairs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:13:44 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/12 14:16:51 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "print_pairs.h"
#include "t_node.h"

#include <stdio.h>

void	print_pairs(t_node *pair_list)
{
	t_pair	*pr = 0;
	t_node	*it = pair_list;

	while (it)
	{
		pr = (t_pair *) it->data;
		printf("[%s][%s]\n", pr->name, pr->value);
		it = it->next;
	}
}
