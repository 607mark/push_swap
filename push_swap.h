/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:09:52 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/04 18:36:57 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	*len_a;
	int	*len_b;
}	t_stacks;

typedef struct s_pair_cost
{
	int	a_top;
	int	a_bot;
	int	b_top;
	int	b_bot;
}	t_pair_cost;

typedef struct s_best_node
{
	int	i;
	int	cost;
}	t_best;

//pushswap funcs
char	*join_args(char *s1, char *s2);
void	push_swap(int *stack_a, int len_a);

//utils
int		ps_arrlen(char **strs);
int		ps_atoi(const char *str, int *n);
int		check_input(char ***strs);
int		check_unique(int *stack_a, int len);
void	free_strs(char ***arr);

//operations
void	op_sa(int *stack_a, int *len_a);
void	op_sb(int *stack_b, int *len_b);
void	op_pa(int *stack_a, int *stack_b, int *len_a, int *len_b);
void	op_pb(int *stack_a, int *stack_b, int *len_a, int *len_b);
void	op_ss(int *stack_a, int *stack_b, int *len_a, int *len_b);
void	op_ra(int *stack_a, int *len_a);
void	op_rb(int *stack_b, int *len_b);
void	op_rra(int *stack_a, int *len_a);
void	op_rrb(int *stack_b, int *len_b);
void	op_rr(int *stack_a, int *stack_b, int *len_a, int *len_b);
void	op_rrr(int *stack_a, int *stack_b, int *len_a, int *len_b);

//sorting
void	sort_3(int *s, int *len);
void	complex_sort(t_stacks *stacks);
void	push_all_back(t_stacks *stacks);
void	max_on_top(t_stacks *stacks);
void	easy_sort(t_stacks s);
//sorting utils
int		is_sorted(int *stack, int len);
int		target_b(t_stacks s, int n);
int		find_max(int *s, int len);
void	init_best(t_best *best);
void	apply_move(t_stacks *s, t_pair_cost *c, int n);
//strategies
void	strat_1(t_stacks *s, t_pair_cost *c);
void	strat_2(t_stacks *s, t_pair_cost *c);
void	strat_3(t_stacks *s, t_pair_cost *c);
void	strat_4(t_stacks *s, t_pair_cost *c);
void	strat_5(t_stacks *s, t_pair_cost *c);
#endif
