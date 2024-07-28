#include "push_swap.h"

char *sort_3(int *s, int len)
{
	if (len == 3)
	{
		if (s[0] > s[1] && s[1] > s[2])
			return ("ra\nsa\n");	
		if (s[0] > s[2] && s[2] > s[1])
			return ("ra\n");
		if (s[2] > s[0] && s[0] > s[1])
	        	return ("sa\n");
		if (s[1] > s[0] && s[0] > s[2])
			return ("rra\n");
		if (s[1] > s[2] && s[2] > s[0])
			return ("sa\nra\n");
	}
	else if (len == 2 && s[0] > s[1])
		return ("sa\n");
}
