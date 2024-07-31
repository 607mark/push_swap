#include "../push_swap.h"

static void do_rev_rotate(int *stack_a, int *len_a)
{

        int     temp;
        int     i;

        if (*len_a < 2)
                return ;
        temp = stack_a[*len_a - 1];

        i = *len_a - 2;
        while(i >= 0)
        {
                stack_a[i + 1] = stack_a[i];
                i--;
        }
        stack_a[0] = temp;
}


void op_rra(int *stack_a, int *len_a)
{
        do_rev_rotate(stack_a, len_a);
	write(1, "rra\n", 4);
}

void op_rrb(int *stack_b, int *len_b)
{
        do_rev_rotate(stack_b, len_b);
	write(1, "rrb\n", 4);
}
void op_rrr(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
        do_rev_rotate(stack_a, len_a);
        do_rev_rotate(stack_b, len_b);
	write(1, "rrr\n", 4);
}
