/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:07:57 by kjaoudi           #+#    #+#             */
/*   Updated: 2021/10/08 17:55:31 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isspace(int c);
int	ft_tolower(int c);
int	ft_toupper(int c);
int	ft_islower(int c);
int	ft_isupper(int c);

#endif
