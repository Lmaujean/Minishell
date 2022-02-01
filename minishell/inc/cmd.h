/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:39:34 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/18 09:12:24 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

typedef struct s_shell	t_shell;
typedef struct s_node	t_node;

int		do_cmds(t_shell *shell);
int		prepare_cmd(t_shell *shell);
int 	check_tokens(t_node *it, t_shell *shell);
int     _redirect(t_node *it);
void    print_error(char *str);
int 	do_builtin(t_node *it, t_shell *shell);
int 	do_bin(t_node *it, t_shell *shell, char **envp);
char 	**to_env(t_shell *shell);
int 	do_assign(t_node *it, t_shell *shell);
void 	do_exec(t_node *it, t_shell *shell, char **envp, int *fds);
int		exec_chevrons(t_node *it, int *fd, t_shell *shell, char **envp);
int 	*handle_chevrons(t_node **it, t_node *token, char **s_error);

#endif
