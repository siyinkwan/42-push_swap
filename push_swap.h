#ifndef H_PUSH
# define H_push

#include <stdlib.h>
#include <stdio.h>

//add prev

typedef struct s_node{
    int value;
    struct s_node *next;
} t_node;

// condiser a *stack within the stack and change the top bottom from node to int
typedef struct s_stack{
    t_node  *top;
    t_node  *bottom;
    int size;
} t_stack;

// add a push_stack struct to contains stack a,b


extern int count;

void    sa(t_stack *stack_a);
void    sb(t_stack *stack_b);
void    ss(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack *stack_a, t_stack *stack_b);
void    pa(t_stack *stack_b, t_stack *stack_a);
void    ra(t_stack *stack_a);
void    rb(t_stack *stack_b);
void    rr(t_stack *stack_a, t_stack *stack_b);
void    rra(t_stack *stack_a);
void    rrb(t_stack *stack_b);
void    rrr(t_stack *stack_a, t_stack *stack_b);

t_stack    *get_stack(char **arr);
int    is_sorted(t_stack *stack);
void    print_stack(t_stack *stack);
int    get_middle_value(t_stack *stack);
void    sort_five(t_stack *stack_a, t_stack *stack_b, int *count);
void    push_min(t_stack *stack_a, t_stack *stack_b, int first_push);
void    split_stack_a(t_stack *stack_a, t_stack *stack_b, int *count);
void    split_stack_b(t_stack *stack_a, t_stack *stack_b, int *count);
int    get_pivots_a(t_stack *stack, int *pivot_min, int *pivot_max);
int    get_pivots_b(t_stack *stack, int *pivot_min, int *pivot_max);
void    recursive_sort_a(t_stack *stack_a, t_stack *stack_b, int *count);
void    recursive_sort_b(t_stack *stack_a, t_stack *stack_b, int *count);
void    sort_stack(t_stack *stack_a, t_stack *stack_b);

#endif