/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:11:31 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/19 10:50:42 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stddef.h>

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memchr(void const *s, int c, size_t n);
void	*ft_memmove(void *dst, void const *src, size_t len);
void	*ft_memcpy(void *dst, void const *src, size_t size);
void	*ft_memccpy(void *dst, void const *src, int c, size_t n);
int		ft_memcmp(void const *s1, void const *s2, size_t n);

int		ft_strncmp(char const *s1, char const *s2, size_t n);
char	*ft_strdup(char const *src);
char	*ft_strndup(char const *src, size_t n);
char	*ft_strnstr(char const *s1, char const *s2, size_t len);
char	*ft_stpcpy(char *dst, char const *src);
char	*ft_stpncpy(char *dst, char const *src, size_t n);
char	*ft_strchr(char const *s, int c);
char	*ft_strrchr(char const *s, int c);
char	*ft_strtok(char *s, char const *delim);
char	*ft_strtrim(char const *str, char const *set);

size_t	ft_strlen(char const *str);
size_t	ft_strnlen(char const *str, size_t maxlen);
size_t	ft_strlcpy(char *dst, char const *src, size_t len);
size_t	ft_strlcat(char *dst, char const *src, size_t len);

#endif
