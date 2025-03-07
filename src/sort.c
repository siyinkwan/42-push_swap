/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:04:49 by sguan             #+#    #+#             */
/*   Updated: 2025/03/07 14:53:50 by sguan            ###   ########.fr       */
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
