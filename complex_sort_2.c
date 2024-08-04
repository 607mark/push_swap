/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:39:28 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/04 15:41:25 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_back(t_stacks *stacks)
{
	while (*stacks->len_b > 0)
		op_pa(stacks->a, stacks->b, stacks->len_a, stacks->len_b);
}

void	max_on_top(t_stacks *stacks)
{
	int	tmp;

	tmp = find_max(stacks->b, *stacks->len_b);
	if (tmp <= *stacks->len_b / 2)
	{
		while (tmp--)
			op_rb(stacks->b, stacks->len_b);
	}
	else
	{
		tmp = *stacks->len_b - tmp;
		while (tmp--)
			op_rrb(stacks->b, stacks->len_b);
	}
}

void	apply_move(t_stacks *s, t_pair_cost *c, t_best *b, int n)
{
	if (n == 1)
		strat_1(s, c, b);
	else if (n == 2)
		strat_2(s, c, b);
	else if (n == 3)
		strat_3(s, c, b);
	else if (n == 4)
		strat_4(s, c, b);
	else if (n == 5)
		strat_5(s, c, b);
	else if (n == 6)
	{
		while (c->b_bot && c->a_bot)
		{
			op_rrr(s->a, s->b, s->len_a, s->len_b);
			--c->b_bot;
			--c->a_bot;
		}
		while (c->b_bot)
		{
			op_rrb(s->b, s->len_b);
			--c->b_bot;
		}
	}
	op_pb(s->a, s->b, s->len_a, s->len_b);
}
