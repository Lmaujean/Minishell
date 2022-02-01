NAME     :=minishell

prefix   :=.
bindir   :=$(prefix)/bin
incdir   :=$(prefix)/inc
srcdir   :=$(prefix)/src
libdir   :=$(prefix)/lib

nodesdir :=$(libdir)/nodes
nodesinc :=$(nodesdir)
nodes.a  :=$(nodesdir)/nodes.a

libftdir :=$(libdir)/libft
libftinc :=$(libftdir)/inc
libft.a  :=$(libftdir)/libft.a

src      := \
	$(wildcard $(srcdir)/*.c) \
	$(wildcard $(srcdir)/*/*.c) \
	$(wildcard $(srcdir)/*/*/*.c)
obj      :=$(src:.c=.o)
bin      :=$(bindir)/$(NAME)
libs     :=$(libft.a) $(nodes.a)

CC       =gcc
CPPFLAGS =-I$(incdir) -I$(libftinc) -I$(nodesinc)
CFLAGS   =-Wall -Wextra -Werror
LDFLAGS  =
LDLIBS   =-lreadline $(libs)


.PHONY: all $(NAME)
all $(NAME): $(libs) $(bin)
all: LDFLAGS+=-L/Users/${USER}/.brew/opt/readline/lib
all: CPPFLAGS+=-I/Users/${USER}/.brew/opt/readline/include

$(libs):
	make -s -j all -C $(libftdir)
	make -s -j all -C $(nodesdir)

$(bin): $(obj) | $(bindir)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(bindir):
	mkdir $@

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $^ -o $@

.PHONY: clean fclean re
clean:
	$(RM) $(obj)

fclean: clean
	$(RM) $(bin)

re: fclean all


.PHONY: linux
linux: all
linux: CC=clang
linux: CPPFLAGS+=-I/usr/local/opt/readline/include
linux: LDFLAGS+=-L/usr/local/opt/readline/lib

.PHONY: run fsan debug norm
run fsan debug: all

debug: CFLAGS+=-g
fsan: LDFLAGS+=-fsanitize=address
run:
	$(bin)
norm:
	norminette $(src) $(inc) $(libftdir) $(nodesdir)
