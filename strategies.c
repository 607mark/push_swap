/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 04:08:25 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/03 04:08:26 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void strat_1(t_stacks *s, t_pair_cost *c, t_best_node *b)
{
    while(c->a_top)
		{
			op_ra(s->a, s->len_a);
			--c->a_top;
		}
		while(c->b_bot)
		{
			op_rrb(s->b, s->len_b);
			--c->b_bot;
		}
}

void strat_2(t_stacks *s, t_pair_cost *c, t_best_node *b)
{
    while(c->b_top)
		{
			op_rb(s->b, s->len_b);
			--c->b_top;
		}	
		while(c->a_bot)
		{
			op_rra(s->a, s->len_a);
			--c->a_bot;
		}
}

void strat_3(t_stacks *s, t_pair_cost *c, t_best_node *b)
{
        while(c->b_top && c->a_top)
		{
			op_rr(s->a, s->b, s->len_a, s->len_b);
			--c->b_top;
			--c->a_top;
		}
		while(c->a_top)
		{
			op_ra(s->a, s->len_a);
			--c->a_top;
		}
}

void strat_4(t_stacks *s, t_pair_cost *c, t_best_node *b)
{
    while(c->b_top && c->a_top)
		{
			op_rr(s->a, s->b, s->len_a, s->len_b);
			--c->b_top;
			--c->a_top;
		}
		while(c->b_top)
		{
			op_rb(s->b, s->len_b);
			--c->b_top;
		}   
}

void strat_5(t_stacks *s, t_pair_cost *c, t_best_node *b)
{
while(c->b_bot && c->a_bot)
		{
			op_rrr(s->a, s->b, s->len_a, s->len_b);
			--c->b_bot;
			--c->a_bot;
		}
		while(c->a_bot)
		{
			op_rra(s->a, s->len_a);
			--c->a_bot;
		}
}
