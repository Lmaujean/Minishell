/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:13:49 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/19 16:29:28 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_node	t_node;
typedef struct s_shell	t_shell;
typedef struct s_pair	t_pair;

t_pair	*get_pair(t_node *list, char const *find);
int		set_pair(t_node **list, char const *find, char const *newval);
int		add_pair(t_node **list, char const *newvar, char const *newval);

char	*get_binpath(char const *find, t_shell *shell);
void	*get_builtin(char const *cmd);
int		get_envp(t_node **env, char **envp);
int		check_assign(t_shell *shell, char const *str, int active);

int		is_op(char c);
int		diff(char const *cmp, char const *ref);
int		*intdup(int val);
char	*var_end(char const *s);
char	*strshift(char *str, char c);
char	*my_strjoin(char const *s1, char const *s2);

void	free_shell(t_shell *shell);
void	free_list(t_node **list);
void	free_pair(t_pair *pair);
void	free_mix(t_node **mix);

#endif
