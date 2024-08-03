/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 04:08:30 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/03 04:08:31 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_strs(char ***arr)
{
	int i;

	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		i++;
	}
	free((*arr)[i]);
	free(*arr);
}

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

int	ps_atoi(const char *str, int *n)
{
	int				s;
	long long int	r;

	s = 1;
	r = 0;
	if (*str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
	{
		if (*(str++) == '-')
			s = -1;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		r = r * 10 + (*(str++) - '0');
		if ((s == -1 && r * s < INT_MIN) || s == 1 && r > INT_MAX)
			return (0);
	}
	*n = (int)(r * s);
	return (1);
}
