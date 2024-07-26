#include "push_swap.h"

int	ps_convert(char **strs, int **stack_a, int *len)
{

	*len = ps_arrlen(strs);
	*stack_a = (int *)malloc(*len * sizeof(int));
	if (!*stack_a)
		return (0);
	printf("num count :%d\n", *len);
	int n = 0;
	while(n < *len)
	{
		printf("%d -- %p\n", n, &(*stack_a)[n]);
		if (ps_atoi(strs[n], ((*stack_a) + n))  == 0)
			return (0);
		printf("stack : %d\n", (*stack_a)[n]);
		n++;
	}
	return (1);
}


int	check_input(char **strs)
{
	if (!check_digits(strs))
		return (0);
}

int main(int ac, char **av)
{
	char	**strs;
	char	*args;
	int	*stack_a;
	int	i;
	int	len;
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
		if (!ps_convert(strs, &stack_a, &len))
			return (write(2, "Error\n", 6));
				
		
		
		
		
		
		
		
		
		
		
		
		
		
		int n = 0;
		while(strs[n] != NULL)
		{
			printf("%s\n", strs[n++]);
		}
	}
}
