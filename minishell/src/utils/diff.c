/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:47:47 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/08 16:40:42 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	diff(char const *cmp, char const *ref)
{
	if (ft_strlen(cmp) != ft_strlen(ref))
		return (1);
	return (ft_strncmp(cmp, ref, ft_strlen(ref)));
}
