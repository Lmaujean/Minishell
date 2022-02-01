#include "nodes.h"
#include "t_node.h"
#include "cmd.h"
#include "utils.h"
#include "types.h"
#include "ft_string.h"
#include "libft.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

static char *ft_joinpair(char *s1, char *s2, char c);
static char **to_arg(t_node *it);
void print_error(char *str);


int	do_bin(t_node *it, t_shell *shell, char **envp)
{
	pid_t 	pid;
	char **arg;
	char *bin;
	int status;

	if (ft_strchr(((t_pair *)it->data)->name, ' '))
		return (127);
	arg = to_arg(it);
	bin = get_binpath(arg[0], shell);
	if (!bin)
		return (127);
	pid = fork();
	if (pid == 0)
	{
		if (execve(bin, arg, envp) == -1)
			printf("%s\n", strerror(errno));
	}
	else
	{
		wait(&status);
		free_split(arg);
		return (WEXITSTATUS(status));
	}
	return (1);
}

char **to_env(t_shell *shell)
{
	char 	**envp;
	char 	**tmp;
	t_node 	*it;
	size_t 	i;

	i = 1;
	it = shell->env;
	while (it && i++)
		it = it->next;
	envp = malloc(sizeof(char *) * i);
	it = shell->env;
	tmp = envp;
	while (it)
	{
		if (((t_pair *)it->data)->name && ((t_pair *)it->data)->value)
			*tmp++ = ft_joinpair(((t_pair *)it->data)->name, ((t_pair *)it->data)->value, '=');
		it = it->next;
	}
	*tmp = 0;
	return (envp);
}

static char **to_arg(t_node *it)
{
	char *tmp;
	char **arg;

	tmp = ft_joinpair(((t_pair *)it->data)->name, ((t_pair *)it->data)->value, ' ');
	arg = ft_split(tmp, ' ');
	free(tmp);
	return (arg);
}

static char *ft_joinpair(char *s1, char *s2, char c)
{
	char *tmp;
	char *res;
	char join[2];

	join[0] = c;
	join[1] = '\0';
	tmp = ft_strjoin(s1, join);
	res = ft_strjoin(tmp, s2);
	free(tmp);
	return (res);
}

void print_error(char *str)
{
	if (str)
		printf("minishell: %s: command not found\n", str);
}
