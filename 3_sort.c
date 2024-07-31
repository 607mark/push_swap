#include "push_swap.h"

void *sort_3(int *s, int *len)
{
	if (*len == 3)
	{
		if (s[0] > s[1] && s[1] > s[2])
		{	
			op_ra(s, len);
			op_sa(s, len);
		}
		else if (s[0] > s[2] && s[2] > s[1])
			op_ra(s, len);
		else if (s[2] > s[0] && s[0] > s[1])
			op_sa(s, len);
		else if (s[1] > s[0] && s[0] > s[2])
			op_rra(s, len);
		else if (s[1] > s[2] && s[2] > s[0])
		{	
			op_sa(s, len);
			op_ra(s, len);
		}
	}
	else if (*len == 2 && s[0] > s[1])
			op_sa(s, len);
}
