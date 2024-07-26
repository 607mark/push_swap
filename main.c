#include "push_swap.h"

int	ps_convert(char **strs, int **stack_a)
{
	stack_a = (int **)malloc(ps_arrlen(strs) * sizeof(int);
	if (!stack_a)
		return (0);
	printf("%d\n", ps_arrlen(strs));
}


int	check_input(char **strs)
{
	if (!check_digits(strs))
		return (0);
}

int main(int ac, char **av)
{
	char **strs;
	char *args;
	int	**stack_a;

	int i;

	i = 1;
	args = NULL;
	strs = NULL;
	stack_a = NULL;
	if(ac > 1)
	{
		while(av[i] != NULL)
			args = join_args(args, av[i++]);
		strs = ft_split(args, ' ');
		free(args);
		if(strs == NULL)
			return (write(2, "Error\n", 6));
		if (!check_input(strs))
			return (write(2, "Error\n", 6));
		if (!ps_convert(strs, stack_a))
			return (write(2, "Error\n", 6));
				
		
		
		
		
		
		
		
		
		
		
		
		
		
		int n = 0;
		while(strs[n] != NULL)
		{
			printf("%s\n", strs[n++]);
		}
	}
}
