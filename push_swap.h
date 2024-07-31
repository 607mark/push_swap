#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
# include "libft/libft.h"
//libft funcs

//size_t  ft_strlen(const char *s);
//char    **ft_split(char const *s, char c);


typedef struct {
    int *a;
    int *b;
    int *len_a;
    int *len_b;
} t_stacks;

//pushswap funcs
char    *join_args(char *s1, char *s2);
void push_swap(int *stack_a, int len_a);

//utils
int	ps_arrlen(char **strs);
int     ps_atoi(const char *str, int *n);
int     check_input(char ***strs);
int     check_unique(int *stack_a, int len);
//freeing utils
void	free_strs(char ***arr);

//operations
void	op_sa(int *stack_a,int *len_a);
void	op_sb(int *stack_b, int *len_b);
void	op_pa(int *stack_a, int *stack_b, int *len_a, int *len_b);
void	op_pb(int *stack_a, int *stack_b, int *len_a, int *len_b);
void	op_ss(int *stack_a, int *stack_b, int *len_a, int *len_b);
void	op_ra(int *stack_a, int *len_a);
void	op_rb(int *stack_b, int *len_b);
void	op_rra(int *stack_a, int *len_a);
void	op_rrb(int *stack_b, int *len_b);
void	op_rr(int *stack_a, int *stack_b, int *len_a, int *len_b);
void	op_rrr(int *stack_a, int *stack_b, int *len_a, int *len_b);

//sorting
void *sort_3(int *s, int *len);
void main_algo( int *s_a, int *s_b, int *len_a, int *len_b);

void push_phase(int *s_a, int *s_b, int *len_a, int *len_b);
void push_back_phase(int *s_a, int *s_b, int *len_a, int *len_b);

//sorting utils
int is_sorted(int *stack, int len);

//temp

void print_stacks(int *stack_a, int *stack_b, int len_a, int len_b);
#endif




