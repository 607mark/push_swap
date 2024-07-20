#include "push_swap.h"

size_t	ps_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	copy_mem(char *dst, char *src, size_t n)
{
	if (dst && src)
	{
		while (n--)
			*(dst++) = *(src++);
	}
}

char	*join_args(char *s1, char *s2)
{
	char	*p;
	size_t	len_s1;
	size_t	len_s2;
	if (!s1)
		len_s1 = 0;
	else
		len_s1 = ps_strlen(s1);
	len_s2 = ps_strlen(s2);
	p = (char *) malloc((len_s1 + len_s2 + 2) * sizeof (char));
	if (!p)
	{
		if (s1)
			free (s1);
		return (NULL);
	}
	copy_mem(p, s1, len_s1);
	*(p + len_s1) = ' ';
	copy_mem(p + len_s1 + 1, s2, len_s2);
	*(p + len_s1 + 1 + len_s2) = '\0';
	if (s1)
		free(s1);
	return (p);
}
