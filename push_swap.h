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

void	swap(t_stack *stack);
void	push(t_stack *src, t_stack *dest);
void	rotate(t_stack *stack);
void	r_rotate(t_stack *stack);

int		get_previous_index(t_stack *stack, int index);
int		length(t_stack *stack);
int		get_next_index(t_stack *stack, int index);

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
int		get_nth_value(t_stack *stack, int n);
int		ft_atoi(const char *nptr);
int		check_dup(int size, int *arr);
void    rank_mapping(int *data, int *mapping, int size);
void    handle_error(t_data *data);

int		sorted(t_stack *stack);
void	handle_min_two(t_data *data);
int		get_min(t_stack *stack);
void	push_min(t_stack *stack_a, t_stack *stack_b, int first_push);
void    sort_stack(t_data *data);
void    sort_two_a(t_stack *stack);
void    sort_three_a(t_stack *stack);
void    sort_five_a(t_data *data);



//for testing
void print_stack_1(t_stack *stack);
void print_stack_2(int *stack, int size);
#endif