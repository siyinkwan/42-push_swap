#include "push_swap.h"

void    get_stack(t_data *data, int size, char **argv)
{
    int i;
	int	*before_map;

	size = size - 1;
	pre_get_stack(data, &data->stack_a, size);
	pre_get_stack(data, &data->stack_b, size);
	before_map = malloc(sizeof(int) * size);
	if (!before_map)
		handle_error(data);
    i = 1;
    while (argv[i])
	{
        if(!check_val(argv[i]))
            handle_error(data);
        before_map[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if(check_dup(size, before_map))
        handle_error(data);
    rank_mapping(before_map, data->stack_a.stack, size);
	data->stack_a.bottom = size - 1;
	free(before_map);
}

void	pre_get_stack(t_data *data, t_stack *pre_stack, int size)
{
		int	i;
		
		i = 0;
		pre_stack->stack = malloc(sizeof(int) * size);
		if (!pre_stack->stack)
			handle_error(data);
		pre_stack->top = 0;
		pre_stack->bottom = 0;
		pre_stack->size = size;
		while(i < size)
		{
			pre_stack->stack[i] = 0;
			i++;
		}
}