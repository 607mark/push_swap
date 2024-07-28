#include "push_swap.h"

int is_sorted(int *stack, int len)
{
	
	while(--len)
	{
		if (stack[len - 1] > stack[len])
			return(0);
	}
	return (1);
}
