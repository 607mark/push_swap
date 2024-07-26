#include "push_swap.h"

int init_b(int **stack_b, int *len_b, int **stack_a, int len_a)
{
	*stack_b =(int *)malloc(len_a * sizeof(int));
	if (!*stack_b)
	{
		free(*stack_a);
		return (0);
	}
	*len_b = 0;
}

void push_swap(int *stack_a, int len_a)
{
	int	*stack_b;
	int	len_b;

	if(!init_b(&stack_b, &len_b, &stack_a, len_a))
		return ;	
}
