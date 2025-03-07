/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:04:31 by sguan             #+#    #+#             */
/*   Updated: 2025/03/07 21:08:43 by sguan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	first_value_a;
	int	first_value_b;
	int	second_value_b;

	while (length(&data->stack_a) > 3)
	{
		first_value_a = get_nth_value(&data->stack_a, 1, 1);
		if (first_value_a == 1 || first_value_a == 2)
			pb(&data->stack_a, &data->stack_b);
		else
			ra(&data->stack_a);
	}
	first_value_b = get_nth_value(&data->stack_b, 1, 1);
	second_value_b = get_nth_value(&data->stack_b, 2, 1);
	if (first_value_b < second_value_b)
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
	return (get_nth_value(stack, n, from_top));
}

int	get_min(t_stack *stack, t_bucket *bucket)
{
	int		size;
	int		min;
	int		i;

	i = 0;
	size = bucket->size;
	if (bucket->pos == 0 || bucket->pos == 2)
		i = stack->top;
	else if (bucket->pos == 1 || bucket->pos == 3)
		i = stack->bottom;
	min = stack->stack[i];
	while (size-- > 0)
	{
		if (stack->stack[i] < min)
			min = stack->stack[i];
		if (bucket->pos == 0 || bucket->pos == 2)
			i = get_next_index(stack, i);
		else if (bucket->pos == 1 || bucket->pos == 3)
			i = get_previous_index(stack, i);
	}
	return (min);
}

int	get_max(t_stack *stack, t_bucket *bucket)
{
	int		size;
	int		max;
	int		i;

	i = 0;
	size = bucket->size;
	if (bucket->pos == 0 || bucket->pos == 2)
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
