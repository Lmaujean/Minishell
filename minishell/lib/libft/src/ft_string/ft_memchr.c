/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:25:21 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/04 16:19:50 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;

	str = (char *) s;
	while (n-- > 0)
	{
		if (*str == (char) c)
			return (str);
		str++;
	}
	return (NULL);
}
