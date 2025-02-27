#include "push_swap.h"

void    sort_stack(t_data *data)
{
	t_bucket	bucket;

    if (data->stack_a.size <= 1 || sorted(&data->stack_a))
        return;
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

	if (bucket->size <= 1)
		return;
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

	set_pivots(data, bucket, &pivot_1, &pivot_2);
	pre_position(bucket->pos, partition);

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
	int	min;
	int max;

	min = get_min(data, bucket);
	max = get_max(data, bucket);
	*pivot_1 = min + (max - min) / 3;
	*pivot_2 = min + 2 * (max - min) / 3;
}

void pre_position(int pos, t_partition	*partition)
{
	partition->min.size = 0;
    partition->mid.size = 0;
    partition->max.size = 0;

    int pos_map[4][3] = {
        {3, 2, 1},
        {3, 2, 0},
        {3, 1, 0},
        {2, 1, 0}
    };
    
    partition->min.pos = pos_map[pos][0];
    partition->mid.pos = pos_map[pos][1];
    partition->max.pos = pos_map[pos][2];
}