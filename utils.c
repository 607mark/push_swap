#include "push_swap.h"

int ps_arrlen(char **strs)
{
	int	i;
	
	i = 0;
	while(strs[i] != NULL)
		i++;
	return (i);
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
		len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
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
//***********************************************

static int     ps_isdigit(int c)
{
        if ((c >= '0' && c <= '9') || c == '-'  || c == '+')
                return (1);
        else
                return (0);
}

int check_digits(char **strs)
{
	int i;
	int j;

	i = 0;
	while(strs[i] != NULL)
	{
		j = 0;
		while(strs[i][j] != '\0')
		{
			if (!(ps_isdigit(strs[i][j])))
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ps_atoi(const char *str, int *n)
{
	int				sign;
	long long int	res;

	sign = 1;
	res = 0;
	if (*str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
	{
		if (*(str++) == '-')
			sign = -1;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*(str++) - '0');
		if (res > INT_MAX || res < INT_MIN)
			return (0);
	}
	*n = (int)res * sign;
	return (1);
}


