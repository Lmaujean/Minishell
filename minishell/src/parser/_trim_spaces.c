#include "libft.h"
#include "utils.h"

static char	*shift(char const *s)
{
	while (*s == ' ')
	{
		if (is_op(*(s - 1)))
			s = strshift((char *) s, ' ');
		if (*(s + 1) == ' ' || is_op(*(s + 1)))
			s++;
		else
			break ;
	}
	return ((char *) s);
}

char	*trim_spaces(char *s)
{
	char const	*ret = s;
	char const	*d = s;
	char		q;

	d = strshift((char *) d, ' ');
	while (*d)
	{
		q = *d;
		if (q == '"' || q == '\'')
		{
			while (*d)
			{
				*s++ = *d++;
				if (*d == q)
					break ;
			}
		}
		d = shift(d);
		*s++ = *d++;
	}
	ft_bzero(s, ft_strlen(s));
	return ((char *) ret);
}
