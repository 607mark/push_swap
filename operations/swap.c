/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 02:54:14 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/03 02:57:30 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	do_swap(int *stack_a, int *len_a)
{
	int	temp;

	if (*len_a > 1)
	{
		temp = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = temp;
	}
}

void	op_sa(int *stack_a, int *len_a)
{
	do_swap(stack_a, len_a);
	write(1, "sa\n", 3);
}

void	op_sb(int *stack_b, int *len_b)
{
	do_swap(stack_b, len_b);
	write(1, "sb\n", 3);
}

void	op_ss(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	do_swap(stack_a, len_a);
	do_swap(stack_b, len_b);
	write(1, "ss\n", 3);
}
