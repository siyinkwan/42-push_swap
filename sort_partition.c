/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_partition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:27:05 by sguan             #+#    #+#             */
/*   Updated: 2025/03/07 14:10:18 by sguan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_pos_zero(t_data *data, t_bucket *bucket)
{
	if (bucket->pos == 1)
		rra(&data->stack_a);
	else if (bucket->pos == 2)
		pa(&data->stack_b, &data->stack_a);
	else if (bucket->pos == 3)
	{
		rrb(&data->stack_b);
		pa(&data->stack_b, &data->stack_a);
	}
	bucket->size = bucket->size - 1;
}

void	sort_two(t_data *data, t_bucket *bucket)
{
	if (bucket->pos == 1)
	{
		rra(&data->stack_a);
		rra(&data->stack_a);
	}
	else if (bucket->pos == 2)
	{
		pa(&data->stack_b, &data->stack_a);
		pa(&data->stack_b, &data->stack_a);
	}
	else if (bucket->pos == 3)
	{
		rrb(&data->stack_b);
		rrb(&data->stack_b);
		pa(&data->stack_b, &data->stack_a);
		pa(&data->stack_b, &data->stack_a);
	}
	sort_two_a(&data->stack_a);
	bucket->size = bucket->size - 2;
}

void	sort_three(t_data *data, t_bucket *bucket)
{
	int		max;
	t_stack	*stack;

	if (bucket->pos == 0 || bucket->pos == 1)
		stack = &data->stack_a;
	else
		stack = &data->stack_b;
	max = get_max(stack, bucket);
	if (bucket->pos == 0)
		sort_three_pos_zero(data, bucket, max);
	else if (bucket->pos == 1)
		sort_three_pos_one(data, bucket, max);
	else if (bucket->pos == 2)
		sort_three_pos_two(data, bucket, max);
	else if (bucket->pos == 3)
		sort_three_pos_three(data, bucket, max);
}

void	sort_three_pos_zero(t_data *data, t_bucket *bucket, int max)
{
	if (data->stack_a.stack[data->stack_a.top] == max)
	{
		sa(&data->stack_a);
		ra(&data->stack_a);
		sa(&data->stack_a);
		rra(&data->stack_a);
	}
	else if (data->stack_a.stack[get_next_index(&data->stack_a, data->stack_a.top)] == max)
	{
		ra(&data->stack_a);
		sa(&data->stack_a);
		rra(&data->stack_a);
	}
	bucket->pos = 0;
	bucket->size = bucket->size - 1;
	sort_two_a(&data->stack_a);
	bucket->size = bucket->size - 2;
}

void	sort_three_pos_one(t_data *data, t_bucket *bucket, int max)
{
	rra(&data->stack_a);
	rra(&data->stack_a);
	if (data->stack_a.stack[data->stack_a.top] == max)
	{
		sa(&data->stack_a);
		rra(&data->stack_a);
	}
	else if (data->stack_a.stack[get_next_index(&data->stack_a, data->stack_a.top)] == max)
	{
		rra(&data->stack_a);
	}
	else
	{
		pb(&data->stack_a, &data->stack_b);
		rra(&data->stack_a);
		sa(&data->stack_a);
		pa(&data->stack_b, &data->stack_a);
	}
	bucket->pos = 0;
	bucket->size = bucket->size - 1;
	sort_two_a(&data->stack_a);
	bucket->size = bucket->size - 2;
}

void	sort_three_pos_two(t_data *data, t_bucket *bucket, int max)
{
	pa(&data->stack_b, &data->stack_a);
	if (data->stack_b.stack[data->stack_b.top] == max)
	{
		pa(&data->stack_b, &data->stack_a);
		sa(&data->stack_a);
	}
	else if (data->stack_b.stack[get_next_index(&data->stack_b, data->stack_b.top)] == max)
	{
		sb(&data->stack_b);
		pa(&data->stack_b, &data->stack_a);
		sa(&data->stack_a);
	}
	else
	{
		pa(&data->stack_b, &data->stack_a);
	}
	pa(&data->stack_b, &data->stack_a);
	bucket->pos = 0;
	bucket->size = bucket->size - 1;
	sort_two(data, bucket);
}

void	sort_three_pos_three(t_data *data, t_bucket *bucket, int max)
{
	rrb(&data->stack_b);
	rrb(&data->stack_b);
	if (data->stack_b.stack[data->stack_b.top] == max)
	{
		pa(&data->stack_b, &data->stack_a);
		rrb(&data->stack_b);
	}
	else if (data->stack_b.stack[get_next_index(&data->stack_b, data->stack_b.top)] == max)
	{
		sb(&data->stack_b);
		pa(&data->stack_b, &data->stack_a);
		rrb(&data->stack_b);
	}
	else
	{
		rrb(&data->stack_b);
		pa(&data->stack_b, &data->stack_a);
	}
	bucket->pos = 2;
	bucket->size = bucket->size - 1;
	bucket->size = bucket->size - 1;
	sort_two(data, bucket);
}