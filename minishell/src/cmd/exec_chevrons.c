#include "nodes.h"
#include "t_node.h"
#include "cmd.h"
#include "utils.h"
#include "builtins.h"
#include "types.h"
#include "ft_string.h"
#include "libft.h"
#include "utils.h"
#include "../tmp/get_delim.h"


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "../tmp/print_pairs.h"

static int try_open(char *file, char *op, int *fd_last, char **s_error);
static int close_fd_last(int *fd_last, int fd, int *heredoc);
static void _heredoc(t_node *token, t_shell *shell, int *fd, int active);

int	exec_chevrons(t_node *it, int *fd, t_shell *shell, char **envp)
{
	int fds[3];

	fds[2] = 0;
	if (fd[0] < 0)
	{
		_heredoc(it->next, shell, &fds[1], fd[1] == 2);
		if (fd[0] != -2)
			fds[0] = -fd[0];
		else
			fds[0] = 0;
		fd[0] *= -1;
	}
	else
		fds[0] = (int)(fd[0] > 2) * fd[0];
	if (fd[1] != 2)
		fds[1] = fd[1];
	else 
		close (fds[2]);
	if (fd[0] != 1)
	{
		do_exec(it, shell, envp, fds);
		return (1);
	}
	return (0);
}

int *handle_chevrons(t_node **it, t_node *token, char **s_error)
{
	int *fd_last;
	int test;
	int heredoc;
	char *op;

	heredoc = 1;
	test = 1;
	fd_last = malloc(sizeof(int) * 2);
	fd_last[0] = 2;
	fd_last[1] = 2;
	while (token && (*(char *)token->data == '<' || *(char *)token->data == '>'))
	{
		op = token->data;
		if ((diff(op, "<") == 0 || *op == '>') && test == 1)
			test = try_open(((t_pair *)token->next->data)->name, op, fd_last, s_error);
		else if (diff(op, "<<") == 0)
			close_fd_last(&fd_last[1], 1, &heredoc);
		token = token->next->next;
		*it = token;
		if (token)
			*it = token->next;
	}
	if (test == 0)
	{
		fd_last[0] = 1 * heredoc;
		return (fd_last);
	}
	fd_last[0] *= heredoc;
	return (fd_last);
}

static int try_open(char *file, char *op, int *fd_last, char **s_error)
{
	int fd;

	fd = -1;
	if (diff(op, "<") == 0)
	{
		fd = open(file, O_RDONLY);
		close_fd_last(&fd_last[1], fd, 0);
	}
	else if (diff(op, ">") == 0)
	{
		fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
		close_fd_last(&fd_last[0], fd, 0);
	}
	else if (diff(op, ">>") == 0)
	{
		fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0644);
		close_fd_last(&fd_last[0], fd, 0);
	}
	if (fd == -1)
	{
		*s_error = my_strjoin(ft_strdup(file), " : ");
		*s_error = my_strjoin(*s_error, ft_strdup(strerror(errno)));
		return(close_fd_last(fd_last, 0, 0));
	}
	return (1);
}

static int close_fd_last(int *fd_last, int fd, int *heredoc)
{
	if (fd > 1)
	{
		if (*fd_last != 2)
				close (*fd_last);
		*fd_last = fd;
	}
	else if (fd == 1)
	{
		if (*fd_last != 2)
				close (*fd_last);
		*fd_last = 2;
		*heredoc *= -1;
	}
	else if (fd == 0 && fd_last[0] != 2 && fd_last[1] != 2)
	{
		close(fd_last[0]);
		close(fd_last[1]);
	}
	return (0);
}

static void _heredoc(t_node *token, t_shell *shell, int *tube, int active)
{
	char *res;
	t_node *last;
	pid_t pid;

	while(token && ((*(char *)token->data == '<' || *(char *)token->data == '>')))
	{
		if (diff((char *)token->data, "<<") == 0)
			last = token->next;
		token = token->next->next;
	}
	res = get_delim(((t_pair *)last->data)->name, shell);
	if (active)
	{	
		pipe(tube);
		pid = fork();
		if (pid == 0)
		{
			close(tube[0]);
			write(tube[1], res, ft_strlen(res));
			close(tube[1]);
			exit(0);
		}
		close(tube[1]);
		wait(NULL);
	}
}

