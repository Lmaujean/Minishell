/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_assign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:55:04 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/18 09:59:14 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "types.h"
#include "t_node.h"

#include <stdio.h>

int	check_assign(t_shell *shell, char const *str, int active)
{
	char		*value;

	value = var_end(str);
	if (*value == '=' && value != str)
	{
		if (active == 1)
		{	
			*value++ = 0;
			if (get_pair(shell->env, str))
				set_pair(&shell->env, str, value);
			else
				set_pair(&shell->var_list, str, value);
		}
		return (1);
	}
	return (0);
}
