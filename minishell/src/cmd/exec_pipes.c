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

// void	exec_pipes(t_node *it, t_shell *shell, char **envp)
// {
// 	t_node *cmd;
// 	t_node *token;
// 	int fds[4];
// 	int tube[2];

// 	fds[0] = 0; fds[1] = 0; fds[2] = 0; fds[3] = 0;
// 	cmd = it;
// 	token = it->next;
// 	while (token && diff(token->data, "|") == 0)
// 	{
// 		pipe(tube);
// 		fds[0] = tube[0];
// 		close(tube[0]); close (tube[1]);

// 	}
// }