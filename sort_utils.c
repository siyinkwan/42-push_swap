#include "push_swap.h"

int	sorted(t_stack	*stack)
{
	int	i;
	int	rank;

	i = stack->top;
	rank = 1;
	while (rank <= stack->size)
	{ 
		if (stack->stack[i] != rank)
			return (0);
		rank++;
		i = get_next_index(stack, i);
	}
	return (1);
}

void	handle_min_two(t_data *data)
{
	while (length(&data->stack_a) > 3)
	{
		if (get_nth_value(&data->stack_a, 1, 1) == 1 || get_nth_value(&data->stack_a, 1, 1) == 2)
			pb(&data->stack_a, &data->stack_b);
		else
			ra(&data->stack_a);
	}
	if (get_nth_value(&data->stack_b, 1, 1) < get_nth_value(&data->stack_b, 2, 1))
		sb(&data->stack_b);
}

int	get_nth_bucket_value(t_data *data, t_bucket	*bucket, int n)
{
	t_stack	*stack;
	bool	from_top;

	if (bucket->pos == 0 || bucket->pos == 1)
		stack = &data->stack_a;
	else
		stack = &data->stack_b;
	from_top = (bucket->pos == 0 || bucket->pos == 2);
	return(get_nth_value(stack, n, from_top));
}

int	get_min(t_data *data, t_bucket *bucket)
{
	t_stack	*stack;
	int		size;
	int		min;
	int		i = 0;

	if (bucket->pos == 0 || bucket->pos == 1)
		stack = &data->stack_a;
	else
		stack = &data->stack_b;
	size = bucket->size;
	if (size == 0 || !stack)
		return (-1);
	if (bucket->pos == 0|| bucket->pos == 2)
		i = stack->top;
	else if (bucket->pos == 1 || bucket->pos == 3)
		i = stack->bottom;
	min = stack->stack[i];

	while (size > 0)
	{
		if (stack->stack[i] < min)
			min = stack->stack[i];
		if (bucket->pos == 0 || bucket->pos == 2)
			i = get_next_index(stack, i);
		else if (bucket->pos == 1 || bucket->pos == 3)
			i = get_previous_index(stack, i);
		size--;
	}
	return (min);
}

int	get_max(t_data *data, t_bucket *bucket)
{
	t_stack	*stack;
	int		size;
	int		max;
	int		i = 0;

	if (bucket->pos == 0 || bucket->pos == 1)
		stack = &data->stack_a;
	else
		stack = &data->stack_b;
	size = bucket->size;
	if (size == 0 || !stack)
		return (-1);
	if (bucket->pos == 0|| bucket->pos == 2)
		i = stack->top;
	else if (bucket->pos == 1 || bucket->pos == 3)
		i = stack->bottom;
	max = stack->stack[i];

	while (size > 0)
	{
		if (stack->stack[i] > max)
			max = stack->stack[i];
		if (bucket->pos == 0 || bucket->pos == 2)
			i = get_next_index(stack, i);
		else if (bucket->pos == 1 || bucket->pos == 3)
			i = get_previous_index(stack, i);
		size--;
	}
	return (max);
}

void	move_to_min(t_data *data, t_bucket *bucket, t_partition *partition)
{
	if (bucket->pos == 0)
	{
		pb(&data->stack_a, &data->stack_b);
		rb(&data->stack_b);
	}
	else if (bucket->pos == 1)
	{
		rra(&data->stack_a);
		pb(&data->stack_a, &data->stack_b);
		rb(&data->stack_b);
	}
	else if (bucket->pos == 2)
	{
		rb(&data->stack_b);
	}
	else if (bucket->pos == 3)
	{
		rrb(&data->stack_b);
	}
	partition->min.size++;
}

void	move_to_mid(t_data *data, t_bucket *bucket, t_partition *partition)
{
	if (bucket->pos == 0)
	{
		pb(&data->stack_a, &data->stack_b);
	}
	else if (bucket->pos == 1)
	{
		rra(&data->stack_a);
		pb(&data->stack_a, &data->stack_b);
	}
	else if (bucket->pos == 2)
	{
		// Stay in place since it's already in B
	}
	else if (bucket->pos == 3)
	{
		rrb(&data->stack_b);
	}
	partition->mid.size++;
}

void	move_to_max(t_data *data, t_bucket *bucket, t_partition *partition)
{
	if (bucket->pos == 0)
	{
		ra(&data->stack_a);
	}
	else if (bucket->pos == 1)
	{
		rra(&data->stack_a);
	}
	else if (bucket->pos == 2)
	{
		pa(&data->stack_b, &data->stack_a);
		ra(&data->stack_a);
	}
	else if (bucket->pos == 3)
	{
		rrb(&data->stack_b);
		pa(&data->stack_b, &data->stack_a);
		ra(&data->stack_a);
	}
	partition->max.size++;
}
