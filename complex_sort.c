/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 03:46:12 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/03 03:46:20 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int strategy(t_stacks stacks, t_pair_cost cost, int i, char hard)
{
	if (hard == 'b')
	{
		if (cost.b_top <= cost.b_bot && cost.b_top >= cost.a_top)
			return (4);
		else if (cost.b_bot <= cost.b_top && cost.b_bot >= cost.a_bot)
			return (6);
		else if (cost.b_top <= cost.b_bot && cost.a_top > cost.a_bot)
			return (2);
		else
			return (1);
	}
	else
	{
		if (cost.a_top <= cost.a_bot && cost.a_top >= cost.b_top)
			return (3);
		else if (cost.a_bot <= cost.a_top && cost.a_bot >= cost.b_bot)
			return (5);
		else if (cost.b_top <= cost.b_bot && cost.a_top >= cost.a_bot)
			return (2);
		else
			return (1);
	}
}

int count_cost(int strat, t_pair_cost cost)
{
	if (strat == 1)
		return (cost.a_top + cost.b_bot);
	else if (strat == 2)
		return (cost.a_bot + cost.b_top);
	else if (strat == 3)
		return (cost.a_top);
	else if (strat == 4)
		return (cost.b_top);	
	else if (strat == 5)
		return (cost.a_bot);
	else if (strat == 6)
		return (cost.b_bot);
}

int	strat_for_node(t_pair_cost *cost, t_stacks stacks, int i)
{
	int target;
	char	hard;
	int	easy_a;
	int	easy_b;

	target = target_b(stacks, i);
	cost->a_top = i;
	cost->a_bot = *(stacks.len_a) - i;
	cost->b_top = target;
	cost->b_bot = *(stacks.len_b) - target;
	if (cost->a_bot >= cost->a_top)
		easy_a = cost->a_top;
	else
		easy_a = cost->a_bot;
	if (cost->b_bot >= cost->b_top)
		easy_b = cost->b_top;
	else
		easy_b = cost->b_bot;
	if (easy_a >= easy_b)
		hard = 'a';
	else
		hard = 'b';
	return (strategy(stacks, *cost, i, hard));
}

void apply_move(t_stacks *s, t_pair_cost *c, t_best_node *b, int n)
{
	if (n == 1)
		strat_1(s, c,b);
	else if (n == 2)
		strat_2(s, c,b);
	else if (n == 3)
		strat_3(s, c,b);
	else if (n == 4)
		strat_4(s, c,b);
	else if (n == 5)
		strat_5(s, c,b);
	else if (n == 6)
	{
		while(c->b_bot && c->a_bot)
		{
			op_rrr(s->a, s->b, s->len_a, s->len_b);
			--c->b_bot;
			--c->a_bot;
		}
		while(c->b_bot)
		{	
			op_rrb(s->b, s->len_b);
			--c->b_bot;
		}
	}
	op_pb(s->a, s->b, s->len_a, s->len_b);
}

void	complex_sort(t_stacks *stacks)
{
	int	i;
	int	tmp;
	
	t_pair_cost cost;
	t_best_node best;

	init_best_node (&best);
	i = 2;
	while (*stacks->len_a > 3 && i--)
		op_pb(stacks->a, stacks->b, stacks->len_a, stacks->len_b);
	while(*stacks->len_a > 0)
	{
		i = 0;
		init_best_node (&best);
		while(i < *stacks->len_a)
		{
			tmp = strat_for_node(&cost, *stacks, i);
			if (count_cost(tmp, cost) < best.cost)
			{
				best.cost = count_cost(tmp, cost);
				best.i = i;
			}
			i++;
		}
		tmp = strat_for_node(&cost, *stacks, best.i);
		apply_move(stacks, &cost, &best, tmp);
	}
	tmp = find_max(stacks->b, *stacks->len_b);
	if (tmp <= *stacks->len_b / 2)
	{
		while(tmp--)
			op_rb(stacks->b, stacks->len_b);
	}
	else
	{
		tmp = *stacks->len_b - tmp;
		while(tmp--)
			op_rrb(stacks->b, stacks->len_b);
	}
	while (*stacks->len_b > 0)
		op_pa(stacks->a, stacks->b, stacks->len_a, stacks->len_b);
}

