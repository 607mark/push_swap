/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 04:08:38 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/03 04:08:39 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int     ps_issign(int c)
{
        if (c == '-'  || c == '+')
                return (1);
        else
                return (0);
}

static int     ps_isdigit(int c)
{
        if (c >= '0' && c <= '9')
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
                        if (ps_issign(strs[i][j]) && j == 0)
                                j++;
                        if (!(ps_isdigit(strs[i][j])))
                                return (0);
                        j++;
                }
                i++;
        }
        return (1);
}

int     check_input(char ***strs)
{
        if (!check_digits(*strs))
        {
                free_strs(strs);
                return (0);
        }
	return (1);
}

int	check_unique(int *stack_a, int len)
{	
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (stack_a[i] == stack_a[j])
			{
				free(stack_a);
				return (0);
			}
				j++;
		}
		i++;
	}
	return (1);
}
