#include "push_swap.h"

void	sort_two_a(t_stack *stack_a)
{
    int top = get_nth_value(stack_a, 1, 1);
	int bot = get_nth_value(stack_a, 2, 1);
	if (top > bot)
		sa(stack_a);
	return;
}

void sort_three_a(t_stack *stack_a)
{
    int top = get_nth_value(stack_a, 1, 1);
    int mid = get_nth_value(stack_a, 2, 1);
    int bot = get_nth_value(stack_a, 3, 1);

	if (top > mid && bot > mid && bot > top)
		sa(stack_a);
	else if (top > mid && bot > mid && top > bot)
		ra(stack_a);
	else if (mid > top && mid > bot && top > bot)
		rra(stack_a);
	else if (mid > top && mid > bot && bot > top)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (top > mid && mid > bot && top > bot)
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_five_a(t_data *data)
{
	handle_min_two(data);
	sort_three_a(&data->stack_a);
	pa(&data->stack_b, &data->stack_a);
	pa(&data->stack_b, &data->stack_a);
}