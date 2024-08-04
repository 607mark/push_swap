/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:25:02 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/04 18:34:56 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	strategy(t_pair_cost cost, char hard)
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

int	count_cost(int strat, t_pair_cost cost)
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
	return (0);
}

int	strat_for_node(t_pair_cost *cost, t_stacks stacks, int i)
{
	char	hard;
	int		target;
	int		easy_a;
	int		easy_b;

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
	return (strategy(*cost, hard));
}

void	find_best(t_stacks *stacks, t_best *best, t_pair_cost *cost, int *i)
{
	int	tmp;

	while (*i < *stacks->len_a)
	{
		tmp = strat_for_node(cost, *stacks, *i);
		if (count_cost(tmp, *cost) < best->cost)
		{
			best->cost = count_cost(tmp, *cost);
			best->i = *i;
		}
		(*i)++;
	}
}

void	complex_sort(t_stacks *stacks)
{
	t_pair_cost	cost;
	t_best		best;
	int			i;
	int			tmp;

	init_best (&best);
	i = 2;
	while (*stacks->len_a > 3 && i--)
		op_pb(stacks->a, stacks->b, stacks->len_a, stacks->len_b);
	while (*stacks->len_a > 0)
	{
		i = 0;
		init_best (&best);
		find_best(stacks, &best, &cost, &i);
		tmp = strat_for_node(&cost, *stacks, best.i);
		apply_move(stacks, &cost, tmp);
	}
	max_on_top(stacks);
	push_all_back(stacks);
}
