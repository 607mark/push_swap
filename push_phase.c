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

void tested(t_stacks stacks)
{
	print_stacks(stacks.a, stacks.b, *(stacks.len_a), *(stacks.len_b));
}

void	push_phase(int *s_a, int *s_b, int *len_a, int *len_b)
{
	int	i;

	t_stacks stacks;

	stacks.a = s_a;
	stacks.b = s_b;
	stacks.len_a = len_a;
	stacks.len_b = len_b;
	
	i = 2;
	while (*len_a > 3 && i--)
		op_pb(s_a, s_b, len_a, len_b);
	
	tested(stacks);
			/*

	while (*len_a > 3)
	{	
		i = 0;
		while(i < *len_a)
		{
		
		}
	}

	*/










}

