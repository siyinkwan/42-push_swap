#include "push_swap.h"

int	sorted(t_stack	*stack)
{
	int	i;
	int	rank;

	i = stack->top;
	rank = 1;
	while (rank <= stack->size)
	{ 
		if (stack->stack[i] != rank)
			return (0);
		rank++;
		i = get_next_index(stack, i);
	}
	return (1);
}

void	handle_min_two(t_data *data)
{
	while (length(&data->stack_a) > 3)
	{
		if (get_nth_value(&data->stack_a, 1) == 1 || get_nth_value(&data->stack_a, 1) == 2)
			pb(&data->stack_a, &data->stack_b);
		else
			ra(&data->stack_a);
	}
	if (get_nth_value(&data->stack_b, 1) < get_nth_value(&data->stack_b, 2))
		sb(&data->stack_b);
}