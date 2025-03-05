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
	// printf("FINAL: ");
	// print_stack_1(&data->stack_a);
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
		{	
			// printf("BEFORE sort_one: ");
			// print_stack_1(&data->stack_b);
			sort_one(data, bucket);
			// printf("AFTER sort_one: ");
			// print_stack_1(&data->stack_b);
		}
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
	{
		//printf("FLAG: %d %d", bucket->size, bucket->pos);
		rra(&data->stack_a);
	}
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
	int max = get_max(data, bucket);

	if (bucket->pos == 0)
	{	
		//printf("BEFORE sort_three_top_a: ");
		//print_stack_1(&data->stack_a);
		sort_three_top_a(data, bucket, max);
		//printf("AFTER sort_three_top_a: ");
		//print_stack_1(&data->stack_a);
	}
	else if (bucket->pos == 1)
	{
		//printf("BEFORE sort_three_BOTTOM_a: ");
		//print_stack_1(&data->stack_a);
		sort_three_bottom_a(data, bucket, max);
		//printf("AFTER sort_three_BOTTOM_a: ");
		//print_stack_1(&data->stack_a);
	}
	else if (bucket->pos == 2)
	{ 
		//printf("BEFORE sort_three_top_B: ");
		//print_stack_1(&data->stack_b);
		sort_three_top_b(data, bucket, max);
		//printf("AFTER sort_three_top_B: ");
		//print_stack_1(&data->stack_b);
	}
	else if (bucket->pos == 3)
	{
		//printf("BEFORE sort_three_BOTTOM_B: ");
		//print_stack_1(&data->stack_b);
		//print_stack_1(&data->stack_b);
		sort_three_bottom_b(data, bucket, max);
		//printf("AFTER sort_three_BOTTOM_B: ");
		//print_stack_1(&data->stack_b);
		//print_stack_1(&data->stack_b);
	}
}

void	sort_three_top_a(t_data *data, t_bucket *bucket, int max)
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


void	sort_three_bottom_a(t_data *data, t_bucket *bucket, int max)
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


void	sort_three_top_b(t_data *data, t_bucket *bucket, int max)
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

void	sort_three_bottom_b(t_data *data, t_bucket *bucket, int max)
{
	rrb(&data->stack_b);
	rrb(&data->stack_b);
	if (data->stack_b.stack[data->stack_b.top] == max)
	{
		//printf("test flag");
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
