#include "push_swap.h"

int	ps_convert(char ***strs, int **stack_a, int *len)
{
	int	n;

	*len = ps_arrlen(*strs);
	*stack_a = (int *)malloc(*len * sizeof(int));
	if (!*stack_a)
	{
		free_strs(strs);
		return (0);
	}
	n = -1;
	while(++n < *len)
	{
		if (ps_atoi((*strs)[n], ((*stack_a) + n))  == 0)
		{	
			free_strs(strs);
			free(*stack_a);
			return (0);
		}
	}
	free_strs(strs);
	return (1);
}

int initialize(char ***strs, char **args, int **stack_a, int *i, int ac)
{
	if (ac < 2)
		return (0);
	*i = 1;
	*args = NULL;
	*strs = NULL;
	*stack_a = NULL;
}

int main(int ac, char **av)
{
	char	**strs;
	char	*args;
	int	*stack_a;
	int	i;
	int	len;

	initialize(&strs, &args, &stack_a, &i, ac);
	while(av[i] != NULL)
		args = join_args(args, av[i++]);
	strs = ft_split(args, ' ');
	free(args);
	if(strs == NULL || !check_input(&strs))
		return (write(2, "Error\n", 6));
	if (!ps_convert(&strs, &stack_a, &len))
		return (write(2, "Error\n", 6));
	if (!(check_unique(stack_a, len)))
		return (write(2, "Error\n", 6));

}
