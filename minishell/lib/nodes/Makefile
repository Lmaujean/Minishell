NAME        :=nodes

prefix      :=.
outdir      :=$(prefix)
incdir      :=$(prefix)
srcdir      :=$(prefix)/src

src         :=$(wildcard $(srcdir)/*.c)
obj         :=$(src:.c=.o)
out         :=$(outdir)/$(NAME).a

MY_CFLAGS   :=-Wshadow -Wdouble-promotion -std=c89 -O3 -pipe
42_CFLAGS   :=-Wall -Wextra -Werror
MY_CPPFLAGS :=-I$(incdir)
42_CPPFLAGS :=

CC          =gcc
AR          :=ar rcs
CPPFLAGS    :=$(42_CPPFLAGS) $(MY_CPPFLAGS)
CFLAGS      :=$(42_CFLAGS)
#$(MY_CFLAGS)

.PHONY: $(NAME) all clean fclean re clang
clang: CC=clang
clang: all

all $(NAME): $(out)

$(out): $(obj)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(obj)

fclean: clean
	$(RM) $(out)

re: fclean all
