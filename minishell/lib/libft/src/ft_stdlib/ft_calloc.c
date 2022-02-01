/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:24:26 by kjaoudi           #+#    #+#             */
/*   Updated: 2021/10/13 11:37:19 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_string.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = malloc(size * count);
	if (ret)
		ft_bzero(ret, size * count);
	return (ret);
}
