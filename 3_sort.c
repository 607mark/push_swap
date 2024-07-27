#include "push_swap.h"

char *sort_3(int *s)
{
	//3 2 1
	if (s[0] > s[1] && s[1] > s[2])
		return ("ra\nsa\n");	
	//3 1 2
	if (s[0] > s[2] && s[2] > s[1])
		return ("ra\n");
	//2 1 3
	if (s[2] > s[0] && s[0] > s[1])
        	return ("sa\n");
	//2 3 1
	if (s[1] > s[0] && s[0] > s[2])
		return ("rra\n");
	//1 3 2
	if (s[1] > s[2] && s[2] > s[0])
		return ("sa\nra\n");
}
