#include <stdio.h>
#include "push_swap.h"

int main(int ac, char **av)
{
	char **strs;
	char *args;
	int i;

	i = 1;
	args = NULL;
	strs = NULL;
	
	if(ac > 1)
	{
		while(av[i] != NULL)
			args = join_args(args, av[i++]);
		strs = ft_split(args, ' ');
		if(strs == NULL)
			return (0);
		int n = 0;
		while(strs[n] != NULL)
		{
			printf("%s\n", strs[n++]);
		}
	}
}
