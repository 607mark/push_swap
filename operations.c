#include "push_swap.h"

int op_sa(int *stack_a,int *len_a)
{
	int	temp;

	if (*len_a > 1)
	{
		temp = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = temp;
	}
}

int op_sb(int *stack_b, int *len_b)
{
	op_sa(stack_b, len_b);
}
int op_pa(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	int	last_index_a;
	int	i;

		
	last_index_a = *len_a - 1;
	if (*len_b > 0)
	{
		while(last_index_a >= 0)
		{
			stack_a[last_index_a + 1] = stack_a[last_index_a];
			last_index_a--;
		}
			(*len_a)++;
		stack_a[0] = stack_b[0];
		i = 0;
		while(i + 1 < *len_b)
		{
			stack_b[i] = stack_b[i + 1];
			i++;
		}
		(*len_b)--;

	}
}

int op_pb(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	op_pa(stack_b, stack_a, len_b, len_a);
}


int op_ss(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	op_sa(stack_a, len_a);
	op_sb(stack_b, len_b);
}

int op_ra(int *stack_a, int *len_a)
{
	int	temp;
	int	i;

	if (*len_a < 2)
		return (0);
	temp = stack_a[0];
	
	i = 1;
	while(i < *len_a)
	{
		stack_a[i - 1] = stack_a[i];
		i++;
	}
	stack_a[*len_a - 1] = temp;
}	

int op_rb(int *stack_b, int *len_b)
{
	op_ra(stack_b, len_b);
}

int op_rr(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	op_ra(stack_a, len_a);
	op_rb(stack_b, len_b);
}

int op_rra(int *stack_a, int *len_a)
{

	int	temp;
	int	i;

	if (*len_a < 2)
		return (0);
	temp = stack_a[*len_a - 1];
	
	i = *len_a - 2;
	while(i >= 0)
	{
		stack_a[i + 1] = stack_a[i];
		i--;
	}
	stack_a[0] = temp;
}
int op_rrb(int *stack_b, int *len_b)
{
	op_rra(stack_b, len_b);
}
int op_rrr(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
	op_rra(stack_a, len_a);
	op_rrb(stack_b, len_b);
}
