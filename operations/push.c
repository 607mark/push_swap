#include "../push_swap.h"

static void do_p(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
        int     last;
        int     i;


        last = *len_a - 1;
        if (*len_b > 0)
        {
                while(last >= 0)
                {
                        stack_a[last + 1] = stack_a[last];
                        last--;
                }
                        (*len_a)++;
                stack_a[0] = stack_b[0];
                i = 0;
                while(i + 1 < *len_b)
                {
                        stack_b[i] = stack_b[i + 1];
                        i++;
                }
                (*len_b)--;

        }
}

void op_pa(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
        do_p(stack_a, stack_b, len_a, len_b);
        write(1, "pa\n", 3);
}

void op_pb(int *stack_a, int *stack_b, int *len_a, int *len_b)
{
        do_p(stack_b, stack_a, len_b, len_a);
        write(1, "pb\n", 3);
}
