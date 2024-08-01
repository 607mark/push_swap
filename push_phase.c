#include "push_swap.h"



int find_max(int *s, int len)
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

int	target_b(int *s_a, int *s_b, int *len_a, int *len_b, int n)
{
	int	i;
	int	target_index;

	i = 0;
	target_index = -1;
	while(i < *len_b)
	{
		if (s_a[n] > s_b[i])
		{
			if (target_index == -1)
				target_index = i;
			else if (s_b[i] > s_b[target_index])
				target_index = i;
		}
		i++;
	}
	if (target_index == -1)
		target_index = find_max(s_b, *len_b);
	return (target_index);
}

void init_struct(t_stacks *stacks, int *s_a, int *s_b, int *len_a, int *len_b)
{
	stacks->a = s_a;
	stacks->b = s_b;
	stacks->len_a = len_a;
	stacks->len_b = len_b;
}

int strategy(t_stacks stacks, t_pair_cost cost, int i, int target, char hard)
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
	int n;
	
	n = INT_MAX;
	if (strat == 1)
		n = cost.a_top + cost.b_bot;
	else if (strat == 2)
		n = cost.a_bot + cost.b_top;
	else if (strat == 3)
		n = cost.a_top;
	else if (strat == 4)
		n = cost.b_top;	
	else if (strat == 5)
		n = cost.a_bot;
	else if (strat == 6)
		n = cost.b_bot;
	return (n);
}

int	strat_for_node(t_pair_cost *cost, t_stacks stacks, int i)
{
	int target;
	char	hard;
	int	easy_a;
	int	easy_b;
	target = target_b(stacks.a, stacks.b, stacks.len_a, stacks.len_b, i);
	//printf("\ntarget for%d is %d\n", i, target);	
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
	/*
	printf("hard is %c\n", hard);
	printf("costs:\n a_top:%d\n", cost->a_top);
	printf("a_bot:%d\n", cost->a_bot);
	printf("b_top:%d\n", cost->b_top);
	printf("b_bot:%d\n", cost->b_bot);
	*/
	return (strategy(stacks, *cost, i, target, hard));
}

void	init_best_node(t_best_node *best)
{
	best->i = -1;
	best->cost = INT_MAX;
}

void apply_move(t_stacks *s, t_pair_cost *c, t_best_node *b, int n)
{
	int target;	
	
	target = target_b(s->a, s->b, s->len_a, s->len_b, b->i);
//	printf("target%d\n", target);
//	printf("str %d\n", n);

	if (n == 1)
	{
		while(c->a_top)
		{
			op_ra(s->a, s->len_a);
			c->a_top--;
		}
		while(c->b_bot)
		{
			op_rrb(s->b, s->len_b);
			c->b_bot--;
		}
	}
	else if (n == 2)
	{
		while(c->b_top)
		{
			op_rb(s->b, s->len_b);
			c->b_top--;
		}	
		while(c->a_bot)
		{
			op_rra(s->a, s->len_a);
			c->a_bot--;
		}
	}
	else if (n == 3)
	{
		while(c->b_top && c->a_top)
		{
			op_rr(s->a, s->b, s->len_a, s->len_b);
			c->b_top--;
			c->a_top--;
		}
		while(c->a_top)
		{
			op_ra(s->a, s->len_a);
			c->a_top--;
		}
	}
	else if (n == 4)
	{
		while(c->b_top && c->a_top)
		{
			op_rr(s->a, s->b, s->len_a, s->len_b);
			c->b_top--;
			c->a_top--;
		}
		while(c->b_top)
		{
			op_rb(s->b, s->len_b);
			c->b_top--;
		}
	}
	else if (n == 5)
	{
		while(c->b_bot && c->a_bot)
		{
			op_rrr(s->a, s->b, s->len_a, s->len_b);
			c->b_bot--;
			c->a_bot--;
		}
		while(c->a_bot)
		{
			op_rra(s->b, s->len_b);
			c->a_bot--;
		}
	}
	else if (n == 6)
	{
		while(c->b_bot && c->a_bot)
		{
			op_rrr(s->a, s->b, s->len_a, s->len_b);
			c->b_bot--;
			c->a_bot--;
		}
		while(c->b_bot)
		{	
			op_rrb(s->b, s->len_b);
			c->b_bot--;
		}
		
	}
	op_pb(s->a, s->b, s->len_a, s->len_b);
	







	return ;
}

void	push_phase(int *s_a, int *s_b, int *len_a, int *len_b)
{
	int	i;
	int	tmp;

	t_stacks stacks;
	t_pair_cost cost;
	t_best_node best;
	init_struct(&stacks, s_a, s_b, len_a, len_b);
	init_best_node (&best);
	i = 2;

	while (*len_a > 3 && i--)
		op_pb(s_a, s_b, len_a, len_b);
	//print_stacks(s_a, s_b, *len_a, *len_b);
	while(*len_a > 3)
	{
		i = 0;
		while(i < *len_a)
		{
			tmp = strat_for_node(&cost, stacks, i);
			int c = count_cost(tmp, cost);
			if (count_cost(tmp, cost) < best.cost)
			{
				best.cost = count_cost(tmp, cost);
				best.i = i;
			}
			i++;
		}
		tmp = strat_for_node(&cost, stacks, best.i);
		apply_move(&stacks, &cost, &best, tmp);
	//	print_stacks(s_a, s_b, *len_a, *len_b);

	}
	//print_stacks(s_a, s_b, *len_a, *len_b);











}

