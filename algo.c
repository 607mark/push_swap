#include "push_swap.h"


void push_back_phase( int *s_a, int *s_b, int *len_a, int *len_b)
{
	return ;
}
void rotate_result(int *s_a, int *len)
{
	return ;
}

void main_algo( int *s_a, int *s_b, int *len_a, int *len_b)
{
	
	if (*len_a > 3)
		push_phase(s_a, s_b, len_a, len_b);
	sort_3(s_a, len_a);
	if (*len_b > 0)
		push_back_phase(s_a, s_b, len_a, len_b);
	if (!is_sorted(s_a, *len_a))
		rotate_result(s_a, len_a);	
	print_stacks(s_a, s_b, *len_a, *len_b);





	free(s_a);
	free(s_b);
}
