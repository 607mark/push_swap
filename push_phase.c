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

void	target_b(int *s_a, int *s_b, int *len_a, int *len_b, int n)
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
}
void	push_phase(int *s_a, int *s_b, int *len_a, int *len_b)
{
	int	i;

	i = 2;
	while (*len_a > 3 && i--)
		op_pb(s_a, s_b, len_a, len_b);
		
}
