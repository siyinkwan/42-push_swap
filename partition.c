/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:53:55 by sguan             #+#    #+#             */
/*   Updated: 2025/03/07 14:54:07 by sguan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_stack(t_data *data, t_bucket *bucket, t_partition *partition)
{
	int	first_bucket_value;
	int	pivot_1;
	int	pivot_2;

	pre_position(bucket->pos, partition);
	set_pivots(data, bucket, &pivot_1, &pivot_2);
	while (bucket->size > 0)
	{
		first_bucket_value = get_nth_bucket_value(data, bucket, 1);

		if (first_bucket_value < pivot_1)
			move_to_min(data, bucket, partition);
		else if (first_bucket_value < pivot_2)
			move_to_mid(data, bucket, partition);
		else
			move_to_max(data, bucket, partition);
		bucket->size--;
	}
}

void	set_pivots(t_data *data, t_bucket *bucket, int *pivot_1, int *pivot_2)
{
	t_stack	*stack;
	int		min;
	int		max;

	if (bucket->pos == 0 || bucket->pos == 1)
		stack = &data->stack_a;
	else
		stack = &data->stack_b;
	min = get_min(stack, bucket);
	max = get_max(stack, bucket);
	*pivot_1 = min + (max - min) / 3;
	*pivot_2 = min + 2 * (max - min) / 3;
}

void	pre_position(int pos, t_partition *partition)
{
	partition->min.size = 0;
	partition->mid.size = 0;
	partition->max.size = 0;

	partition->min.pos = 3 - (pos == 3);
	partition->mid.pos = 2 - (pos >= 2);
	partition->max.pos = 1 - (pos >= 1);
}
