/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjaoudi <kjaoudi@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:47:41 by kjaoudi           #+#    #+#             */
/*   Updated: 2022/01/31 13:34:57 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "tmp/print_nodes.h"

static void	sighandler(int sig)
{
	if (sig == SIGINT || sig == SIGQUIT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static void	init_sig_term(struct sigaction *s_act, struct termios *term)
{
	// tcgetattr(STDIN_FILENO, term);
	// term->c_lflag &= ECHO;
	// tcsetattr(STDIN_FILENO, TCSANOW, term);
	(void)term;
	s_act->sa_handler = sighandler;
	s_act->sa_flags = SA_SIGINFO;
	sigaction(SIGINT, s_act, NULL);
	sigaction(SIGQUIT, s_act, NULL);
}

int	main(int ac, char **av, char **envp)
{
	t_shell				shell;
	struct sigaction	s_act;
	struct termios		term;

	shell = (t_shell){0};
	init_sig_term(&s_act, &term);
	if (ac == 1 && av[1] == 0 && get_envp(&(shell.env), envp))
	{
		shell.input = readline("\e[1;34mminishell $\e[0m ");
		while (shell.input)
		{
			if (*shell.input)
				add_history(shell.input);
			shell.cmd_list = tokenize(shell.input, &shell);
			if (shell.cmd_list)
			{
				do_cmds(&shell);
			}
			else
				printf("warning : unclosed quotes\n");
			free(shell.input);
			node_clear(&(shell.cmd_list));
			shell.input = readline("\e[1;34mminishell $\e[0m ");
		}
		quit(&shell, 0);
	}
	return (EXIT_FAILURE);
}
