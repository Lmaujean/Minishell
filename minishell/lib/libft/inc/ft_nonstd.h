/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nonstd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 08:30:25 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/07 13:23:21 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NONSTD_H
# define FT_NONSTD_H

# include <stddef.h>

char	*ft_itoa(int n);
char	*ft_getfile(char const *path);
char	**ft_split(char const *s, char c);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnjoin(char const *s1, char const *s2, size_t n);

size_t	ft_nbrlen_base(long long n, int base);
void	ft_putnbr_fd(long n, int const fd);
void	ft_putchar_fd(char c, int const fd);
void	ft_putstr_fd(char const *s, int const fd);
void	ft_putendl_fd(char const *s, int const fd);
void	*free_split(char **split);
void	*ft_free(void *p);

#endif
