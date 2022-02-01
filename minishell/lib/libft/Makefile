NAME        :=libft

prefix      :=.
outdir      :=$(prefix)
incdir      :=$(prefix)/inc
srcdir      :=$(prefix)/src

src_ctype   :=$(wildcard $(srcdir)/ft_ctype/*.c)
src_stdio   :=$(wildcard $(srcdir)/ft_stdio/*.c)
src_stdlib  :=$(wildcard $(srcdir)/ft_stdlib/*.c)
src_string  :=$(wildcard $(srcdir)/ft_string/*.c)
src_nonstd  :=$(wildcard $(srcdir)/ft_nonstd/*.c)

src         :=\
	$(src_ctype)\
	$(src_stdio)\
	$(src_stdlib)\
	$(src_string)\
	$(src_nonstd)

obj         :=$(src:.c=.o)
out         :=$(outdir)/$(NAME).a

MY_CFLAGS   :=-Wshadow -Wdouble-promotion -std=c89 -O3 -pipe
42_CFLAGS   :=-Wall -Wextra -Werror
MY_CPPFLAGS :=-I$(incdir)
42_CPPFLAGS :=

AR          :=ar rcs
CC          =gcc
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
