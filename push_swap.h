#ifndef H_PUSH
# define H_push

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

typedef struct s_node{
    int value;
    struct s_node *next;
} t_node;

typedef struct s_chunk{
    int loc;
    int size;
}	t_chunk;

typedef struct s_stack{
	int	*stack;
	int	top;
    int	bottom;
    int size;
} t_stack;

typedef struct s_data
{
	t_stack	stack_a;
	t_stack stack_b;
} t_data;

extern int count;

void	swap(t_stack *stk);
void	push(t_stack *src, t_stack *dest);
void	rotate(t_stack *stk);
void	r_rotate(t_stack *stk);

int		next_up(t_stack *stk, int index);
int		length(t_stack *stack);
int		next_down(t_stack *stk, int index);

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

void    get_stack(t_data *data, int argc, char **argv);
void	pre_get_stack(t_data *data, t_stack *pre_stack, int size);
int		check_val(char *str);
int		ft_atoi(const char *nptr);
int		check_dup(int size, int *arr);
void    rank_mapping(int *data, int *mapping, int size);
void    handle_error(t_data *data);

// t_stack    *get_stack(char **arr);
// int    is_sorted(t_stack *stack);
// void    print_stack(t_stack *stack);
// int    get_middle_value(t_stack *stack);
// void    sort_five(t_stack *stack_a, t_stack *stack_b, int *count);
// void    push_min(t_stack *stack_a, t_stack *stack_b, int first_push);
// void    split_stack_a(t_stack *stack_a, t_stack *stack_b, int *count);
// void    split_stack_b(t_stack *stack_a, t_stack *stack_b, int *count);
// int    get_pivots_a(t_stack *stack, int *pivot_min, int *pivot_max);
// int    get_pivots_b(t_stack *stack, int *pivot_min, int *pivot_max);
// void    recursive_sort_a(t_stack *stack_a, t_stack *stack_b, int *count);
// void    recursive_sort_b(t_stack *stack_a, t_stack *stack_b, int *count);
// void    sort_stack(t_stack *stack_a, t_stack *stack_b);

#endif