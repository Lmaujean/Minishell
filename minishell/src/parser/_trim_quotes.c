char	*trim_quotes(char *s)
{
	char const	*ret = s;
	char		*d;
	char		q;

	d = s;
	while (*d)
	{
		q = *d;
		if (q == '"' || q == '\'')
		{
			d++;
			while (*d != q)
				*s++ = *d++;
			d++;
		}
		else
			*s++ = *d++;
	}
	*s = 0;
	return ((char *) ret);
}
