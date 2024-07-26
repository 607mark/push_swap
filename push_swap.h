#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

//libft funcs

size_t  ft_strlen(const char *s);
char    **ft_split(char const *s, char c);


//pushswap funcs
char    *join_args(char *s1, char *s2);
void push_swap(int *stack_a, int len_a);

//utils
int ps_arrlen(char **strs);
int     ps_atoi(const char *str, int *n);
int     check_input(char ***strs);
int     check_unique(int *stack_a, int len);
//freeing utils
void free_strs(char ***arr);

#endif




