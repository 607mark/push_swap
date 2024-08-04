/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 04:08:17 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/04 15:50:34 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_best(t_best *best)
{
	best->i = -1;
	best->cost = INT_MAX;
}

int	find_max(int *s, int len)
{
	int	max;
	int	i;

	i = 0;
	max = i;
	while (i < len)
	{
		if (s[i] > s[max])
			max = i;
		i++;
	}
	return (max);
}

int	target_b(t_stacks s, int n)
{
	int	i;
	int	target_index;

	i = 0;
	target_index = -1;
	while (i < *s.len_b)
	{
		if (s.a[n] > s.b[i])
		{
			if (target_index == -1)
				target_index = i;
			else if (s.b[i] > s.b[target_index])
				target_index = i;
		}
		i++;
	}
	if (target_index == -1)
		target_index = find_max(s.b, *s.len_b);
	return (target_index);
}

int	is_sorted(int *stack, int len)
{
	while (--len)
	{
		if (stack[len - 1] > stack[len])
			return (0);
	}
	return (1);
}

void	sort_3(int *s, int *len)
{
	if (*len == 3)
	{
		if (s[0] > s[1] && s[1] > s[2])
		{
			op_ra(s, len);
			op_sa(s, len);
		}
		else if (s[0] > s[2] && s[2] > s[1])
			op_ra(s, len);
		else if (s[2] > s[0] && s[0] > s[1])
			op_sa(s, len);
		else if (s[1] > s[0] && s[0] > s[2])
			op_rra(s, len);
		else if (s[1] > s[2] && s[2] > s[0])
		{
			op_sa(s, len);
			op_ra(s, len);
		}
	}
	else if (*len == 2 && s[0] > s[1])
		op_sa(s, len);
}
