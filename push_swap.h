#ifndef H_PUSH
# define H_push

#include <stdlib.h>

extern  int op_count;

typedef struct s_node{
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack{
    t_node  *top;
    t_node  *bottom;
    int size;
} t_stack;

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
void    get_pivots(t_stack *stack, int *pivot_min, int *pivot_max);
void    split_stack(t_stack *stack_a, t_stack *stack_b);
#endif