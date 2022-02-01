/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 07:34:52 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/14 08:43:11 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

#include <stdio.h>

int	history(t_shell *shell, char const *args)
{
	if (shell && !args)
		return (1);
	return (0);
}
