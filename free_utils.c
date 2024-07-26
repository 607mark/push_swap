#include "push_swap.h"

void free_strs(char ***arr)
{
	int i;

	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		i++;
	}
	free((*arr)[i]);
	free(*arr);
}
