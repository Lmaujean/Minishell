/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 07:32:57 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/09 08:24:49 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

static int	is_valid(char c)
{
	return (ft_isalpha(c) || ft_isdigit(c) || c == '_');
}

char	*var_end(char const *s)
{
	if (!ft_isdigit(*s))
		while (*s && is_valid(*s))
			s++;
	return ((char *) s);
}
