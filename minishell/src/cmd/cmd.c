/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 07:34:26 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/18 10:10:31 by kjaoudi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nodes.h"
#include "t_node.h"
#include "cmd.h"
#include "utils.h"
#include "builtins.h"
#include "types.h"
#include "ft_string.h"
#include "libft.h"

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

/*		TEMPORAIRE		*/
#include "../tmp/print_nodes.h"
#include "../tmp/print_pairs.h"

void	print_mix(t_node *cmd_list);
static t_node *to_next(t_node *it, t_shell *shell, char **envp, char **s_error);

int do_cmds(t_shell *shell)
{
	t_node 	*it;
	char 	**envp;
	char 	*s_error;

	if (!prepare_cmd(shell))
		return (0);
	envp = to_env(shell);
	s_error = NULL;
	it = shell->cmd_list;
	while (it)
		it = to_next(it, shell, envp, &s_error);
	if (s_error)
		free(s_error);
	free_split(envp);
	return (0);
}

void do_exec(t_node *it, t_shell *shell, char **envp, int *fds)
{
	pid_t pid;
	int status;
	int fd_stdin;
	int fd_stdout;

	if (diff(((t_pair *)it->data)->name, "exit") == 0\
		|| diff(((t_pair *)it->data)->name, "cd") == 0\
		|| diff(((t_pair *)it->data)->name, "unset") == 0\
		|| diff(((t_pair *)it->data)->name, "export") == 0)
		do_builtin(it,shell);
	else
	{
		fd_stdin = dup(0);
		fd_stdout = dup(1);
		pid = fork();
		if (pid == 0)
		{
			if (fds[0] > 0)
			{
				dup2(fds[0], 1);
				close(fds[0]);
			}
			if (fds[1] > 0)
			{
				if (fds[2] != 0)
					close(fds[2]);
				dup2(fds[1], 0);
				close(fds[1]);
			}
			if (do_builtin(it, shell) == 0)
				if (do_bin(it, shell, envp) == 127){
					exit(EXIT_FAILURE);
				}
			exit(EXIT_SUCCESS);
		}
		else
		{
			close(0);
			dup2(fd_stdin, 0);
			wait(&status);
			if (WEXITSTATUS(status) == EXIT_FAILURE && do_assign(it, shell) == 0)
				print_error(((t_pair *)it->data)->name);
		}
	}
}

static t_node *to_next(t_node *it, t_shell *shell, char **envp, char **s_error)
{
	t_node 	*next_cmd;
	int fds[3];

	fds[0] = 0; fds[1]=0; fds[2]=0;
	if (it->next && it->next->next)
		next_cmd = it->next->next;
	else
		next_cmd = it->next;
	if (it->next && (*((char *)it->next->data) == '>' || *((char *)it->next->data) == '<'))
	{
		if (exec_chevrons(it, handle_chevrons(&next_cmd, it->next, s_error), shell, envp) == 0)
			printf("%s\n", *s_error);
	}
	else if (it->next && (*((char *)it->next->data) == '|'))
		printf("pipe\n");//exec_pipes(handle_pipes(it), shell, envp);
	else
		do_exec(it, shell, envp, fds);
	return (next_cmd);
}


