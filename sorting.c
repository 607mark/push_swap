#include "push_swap.h"

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
		printf("#%d = %d\n",i, stack_b[i++]);
}

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
	
	len_b = 3;
	stack_b[0] = 0;
	stack_b[1] = 10;
	stack_b[2] = 20;
	
	print_stacks(stack_a, stack_b, len_a, len_b);
	op_rrr(stack_a,stack_b, &len_a, &len_b);
	print_stacks(stack_a, stack_b, len_a, len_b);
}
