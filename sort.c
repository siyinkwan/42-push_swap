#include "push_swap.h"

void    sort_stack(t_data *data)
{
    if (data->stack_a.size <= 1 || sorted(&data->stack_a))
        return;
	else if (data->stack_a.size == 2)
        sort_two_a(&data->stack_a);	
    else if (data->stack_a.size == 3)
        sort_three_a(&data->stack_a);
	else if (data->stack_a.size == 5)
        sort_five_a(data);
	else
		quick_sort(data);
}

void	partition_stack(t_data	*data, t_bucket	*bucket, t_partition *partition)
{
	int	first_bucket_value;
	int	pivot_1;
	int	pivot_2;

    if (bucket->pos = 0 || bucket->pos == 1)
        pivot_1 = 2 * bucket->size / 3;

	if (bucket->pos = 2 || bucket->pos == 3)
        pivot_1 = bucket->size / 2;
	pre_position(bucket->pos, partition);
	while(bucket->size > 0)
	{
		first_bucket_value = get_nth_bucket_value(data, bucket, 1);
		if (first_bucket_value > pivot_1)







		bucket->size--;
	}

}

void	set_pivots(t_data	*data, t_bucket	*bucket, int *pivot_1, int *pivot_2)
{
	
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
