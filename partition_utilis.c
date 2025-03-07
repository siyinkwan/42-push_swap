/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:11:42 by sguan             #+#    #+#             */
/*   Updated: 2025/03/07 14:42:26 by sguan            ###   ########.fr       */
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
		pa(&data->stack_b, &data->stack_a);
		ra(&data->stack_a);

	}
	else if (bucket->pos == 3)
	{
		rrb(&data->stack_b);
		pa(&data->stack_b, &data->stack_a);
		ra(&data->stack_a);
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
	}
	else if (bucket->pos == 3)
	{
		rrb(&data->stack_b);
		pa(&data->stack_b, &data->stack_a);
	}
	partition->max.size++;
}
