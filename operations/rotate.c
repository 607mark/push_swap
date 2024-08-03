/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 03:05:12 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/03 03:06:54 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static void	do_rotate(int *stack_a, int *len_a)
{
	int	temp;
	int	i;

	if (*len_a < 2)
		return ;
	temp = stack_a[0];
	i = 1;
	while (i < *len_a)
	{
		stack_a[i - 1] = stack_a[i];
		i++;
	}
	stack_a[*len_a - 1] = temp;
}

void	op_ra(int *stack_a, int *len_a)
{
	do_rotate(stack_a, len_a);
	write(1, "ra\n", 3);
}

void	op_rb(int *stack_b, int *len_b)
{
	do_rotate(stack_b, len_b);
	write(1, "rb\n", 3);
}

void	op_rr(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	do_rotate(stack_a, len_a);
	do_rotate(stack_b, len_b);
	write(1, "rr\n", 3);
}
