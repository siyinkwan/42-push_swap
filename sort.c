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
			sort_one(data, bucket);
		// printf("A:");
		// print_stack_1(&data->stack_a);
		// printf("B:");
		// print_stack_1(&data->stack_b);
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
		// printf("A:");
		// print_stack_1(&data->stack_a);
		// printf("B:");
		// print_stack_1(&data->stack_b);
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

void	sort_one(t_data *data, t_bucket *bucket)
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
		//rrb(&data->stack_b);////////////////////////////////////////////// TODO:review small sort logic
		pa(&data->stack_b, &data->stack_a);
		pa(&data->stack_b, &data->stack_a);
	}
	sort_two_a(&data->stack_a);
	bucket->size = bucket->size - 2;
}

void	sort_three(t_data *data, t_bucket *bucket)
{
	int max = get_max(data, bucket);

	if (bucket->pos == 0) // stack_a 顶部
		sort_three_top_a(data, max);
	else if (bucket->pos == 1) // stack_a 底部
		sort_three_bottom_a(data, max);
	else if (bucket->pos == 2) // stack_b 顶部
		sort_three_top_b(data, max);
	else if (bucket->pos == 3) // stack_b 底部
		sort_three_bottom_b(data, max);

	bucket->size -= 3;
}

void	sort_three_top_a(t_data *data, int max)
{
	int top = get_nth_value(&data->stack_a, 1, 1);
	int mid = get_nth_value(&data->stack_a, 2, 1);
	//int bot = get_nth_value(&data->stack_a, 3, 1);

	if (top == max)
	{
		sa(&data->stack_a);
		ra(&data->stack_a);
		sa(&data->stack_a);
		rra(&data->stack_a);
	}
	else if (mid == max)
	{
		ra(&data->stack_a);
		sa(&data->stack_a);
		rra(&data->stack_a);
	}

	sort_two_a(&data->stack_a);
}


void	sort_three_bottom_a(t_data *data, int max)
{
	rra(&data->stack_a);
	rra(&data->stack_a);
	rra(&data->stack_a);//////////////////////////////////
	if (get_nth_value(&data->stack_a, 1, 1) == max)
	{
		sa(&data->stack_a);
		rra(&data->stack_a);
	}
	else if (get_nth_value(&data->stack_a, 2, 1) == max)
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

	sort_two_a(&data->stack_a);
}


void	sort_three_top_b(t_data *data, int max)
{
	pa(&data->stack_b, &data->stack_a);
	if (get_nth_value(&data->stack_b, 1, 1)== max)
	{
		pa(&data->stack_b, &data->stack_a);
		sa(&data->stack_a);
	}
	else if (get_nth_value(&data->stack_b, 2, 1) == max)
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

	sort_two_a(&data->stack_a);
}


void	sort_three_bottom_b(t_data *data, int max)
{
	rrb(&data->stack_b);
	rrb(&data->stack_b);
	if (get_nth_value(&data->stack_a, 1, 1) == max)
	{
		pa(&data->stack_b, &data->stack_a);
		rrb(&data->stack_b);
	}
	else if (get_nth_value(&data->stack_b, 2, 1) == max)
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
	pa(&data->stack_b, &data->stack_a);

	sort_two_a(&data->stack_a);
}
