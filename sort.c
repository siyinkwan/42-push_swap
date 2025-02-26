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

