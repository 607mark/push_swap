/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 04:07:58 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/04 15:24:04 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_b(int **stack_b, int *len_b, int **stack_a, int len_a)
{
	if (!is_sorted(*stack_a, len_a))
	{
		*stack_b = (int *)malloc (len_a * sizeof(int));
		if (!*stack_b)
		{
			free(*stack_a);
			return (0);
		}
		*len_b = 0;
	}
	else
	{
		free(*stack_a);
		return (0);
	}
}

static void	main_algo(int *s_a, int *s_b, int *len_a, int *len_b)
{
	t_stacks	stacks;

	stacks.a = s_a;
	stacks.b = s_b;
	stacks.len_a = len_a;
	stacks.len_b = len_b;
	if (*len_a > 3)
		complex_sort(&stacks);
	else if (*len_a <= 3)
		sort_3(s_a, len_a);
	free(s_a);
	free(s_b);
}

void	push_swap(int *stack_a, int len_a)
{
	int	*stack_b;
	int	len_b;

	if (!init_b(&stack_b, &len_b, &stack_a, len_a))
		return ;
	main_algo(stack_a, stack_b, &len_a, &len_b);
}

/*
void print_stacks(int *stack_a, int *stack_b, int len_a, int len_b)
{
	int i = 0;
	printf("======stack a======\n");
	printf("len_a=%d\n", len_a);
	while(i < len_a)
	{
		printf("#%d = %d\n",i,  stack_a[i]);
		i++;
	}
	i = 0;
	printf("======stack b======\n");
	printf("len_b=%d\n", len_b);
	while(i < len_b)
	{
		printf("#%d = %d\n",i, stack_b[i]);
		i++;
	}
}*/
