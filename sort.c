/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:04:49 by sguan             #+#    #+#             */
/*   Updated: 2025/03/07 14:06:48 by sguan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_data *data)
{
	t_bucket	bucket;

	if (data->stack_a.size <= 1 || sorted(&data->stack_a))
		return ;
	else if (data->stack_a.size == 2)
		sort_two_a(&data->stack_a);
	else if (data->stack_a.size == 3)
		sort_three_a(&data->stack_a);
	else if (data->stack_a.size == 5)
		sort_five_a(data);
	else
	{
		bucket.pos = 0;
		bucket.size = data->stack_a.size;
		quick_sort(data, &bucket);
	}
}

void	quick_sort(t_data *data, t_bucket *bucket)
{
	t_partition	partition;

	if (bucket->pos == 3 && length(&data->stack_b) == bucket->size)
		bucket->pos = 2;
	if (bucket->pos == 1 && length(&data->stack_a) == bucket->size)
		bucket->pos = 0;
	if (bucket->size <= 3)
	{
		if (bucket->size == 3)
			sort_three(data, bucket);
		else if (bucket->size == 2)
			sort_two(data, bucket);
		else if (bucket->size == 1)
			move_to_pos_zero(data, bucket);
		return ;
	}
	partition_stack(data, bucket, &partition);
	if (partition.max.size > 0)
		quick_sort(data, &partition.max);
	if (partition.mid.size > 0)
		quick_sort(data, &partition.mid);
	if (partition.min.size > 0)
		quick_sort(data, &partition.min);
}

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
