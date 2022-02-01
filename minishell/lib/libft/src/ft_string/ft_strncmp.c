/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:26:07 by kjaoudi           #+#    #+#             */
/*   Updated: 2021/10/13 11:52:14 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_string.h"

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	if (n > ft_strlen(s1))
		n = ft_strlen(s1) + 1;
	else if (n > ft_strlen(s2))
		n = ft_strlen(s2) + 1;
	return (ft_memcmp(s1, s2, n));
}
