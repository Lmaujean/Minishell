/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_delim.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:52:58 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/19 13:24:27 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_DELIM_H
# define GET_DELIM_H

typedef struct s_shell	t_shell;

char	*get_delim(char const *delim, t_shell *shell);

#endif
