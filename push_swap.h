/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:03:08 by sguan             #+#    #+#             */
/*   Updated: 2025/03/06 21:42:20 by sguan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_PUSH
# define H_push

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct s_node{
    int value;
    struct s_node *next;
} t_node;

typedef struct s_bucket {
    int pos;
    int size;
} t_bucket;

typedef struct s_partition
{
    t_bucket min;
    t_bucket mid;
    t_bucket max;
} t_partition;

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

void	swap(t_stack *stack);
void	push(t_stack *src, t_stack *dest);
void	rotate(t_stack *stack);
void	r_rotate(t_stack *stack);

int		length(t_stack *stack);
int		get_previous_index(t_stack *stack, int index);
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

void    get_stack(t_data *data, int argc, char **arr);
void	pre_get_stack(t_data *data, t_stack *pre_stack, int size);
int		check_val(char *str);
int		get_nth_value(t_stack *stack, int n, bool from_top);
int		ft_atoi(const char *nptr);
char	*ft_strchr(const char *s, int c);
int		check_dup(int size, int *arr);
void    rank_mapping(int *data, int *mapping, int size);
void    handle_error(t_data *data);
int		word_count(char *str);
char	*get_word(char *str, int start, int end);
char	**ft_split(char *str);

int		sorted(t_stack *stack);
void	quick_sort(t_data *data, t_bucket *bucket);
void	handle_min_two(t_data *data);
void    sort_stack(t_data *data);
void	partition_stack(t_data	*data, t_bucket	*bucket, t_partition *partition);
void	set_pivots(t_data *data, t_bucket *bucket, int *pivot_1, int *pivot_2);
void	pre_position(int pos, t_partition	*partition);
void    sort_two_a(t_stack *stack);
void    sort_three_a(t_stack *stack);
void    sort_five_a(t_data *data);

void	move_to_pos_zero(t_data *data, t_bucket *bucket);
void	sort_two(t_data *data, t_bucket *bucket);
void	sort_three(t_data *data, t_bucket *bucket);
void	sort_three_pos_zero(t_data *data, t_bucket *bucket, int max);
void	sort_three_pos_one(t_data *data, t_bucket *bucket, int max);
void	sort_three_pos_two(t_data *data, t_bucket *bucket, int max);
void	sort_three_pos_three(t_data *data, t_bucket *bucket, int max);

int		get_nth_bucket_value(t_data *data,t_bucket	*bucket, int n);
int		get_min(t_data *data, t_bucket *bucket);
int		get_max(t_data *data, t_bucket *bucket);
void	move_to_min(t_data *data, t_bucket *bucket, t_partition *partition);
void	move_to_mid(t_data *data, t_bucket *bucket, t_partition *partition);
void	move_to_max(t_data *data, t_bucket *bucket, t_partition *partition);

#endif