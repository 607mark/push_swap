/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:46:35 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/04 17:48:09 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stacks s)
{
	int	min;
	int	i;

	i = 0;
	min = i;
	while (i < *s.len_a)
	{
		if (s.a[i] < s.a[min])
			min = i;
		i++;
	}
	return (min);
}

void	min_on_top(t_stacks stacks)
{
	int	tmp;

	tmp = find_min(stacks);
	if (tmp <= *stacks.len_a / 2)
	{
		while (tmp--)
			op_ra(stacks.a, stacks.len_a);
	}
	else
	{
		tmp = *stacks.len_a - tmp;
		while (tmp--)
			op_rra(stacks.a, stacks.len_a);
	}
}

int	target_a(t_stacks s, int n)
{
	int	i;
	int	target_index;

	i = 0;
	target_index = -1;
	while (i < *s.len_a)
	{
		if (s.b[n] < s.a[i])
		{
			if (target_index == -1)
				target_index = i;
			else if (s.a[i] < s.a[target_index])
				target_index = i;
		}
		i++;
	}
	if (target_index == -1)
		target_index = find_min(s);
	return (target_index);
}

void	easy_sort(t_stacks s)
{
	while (*s.len_a > 3 && !is_sorted(s.a, *s.len_a))
		op_pb(s.a, s.b, s.len_a, s.len_b);
	sort_3(s.a, s.len_a);
	while (*s.len_b > 0)
	{
		if (target_a(s, 0) < *s.len_a / 2)
		{
			while (target_a(s, 0) != 0)
				op_ra(s.a, s.len_a);
		}
		else
		{
			while (target_a(s, 0) != 0)
				op_rra(s.a, s.len_a);
		}
		op_pa(s.a, s.b, s.len_a, s.len_b);
	}
	min_on_top(s);
}
