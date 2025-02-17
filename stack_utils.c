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
    while (i < size)
	{
        if(!check_val(argv[i]))
		{
			printf("TEST VAL\n");
            handle_error(data);
		}
        before_map[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if(check_dup(size, before_map))
	{	
		printf("TEST DUP\n");
        handle_error(data);
	}
	rank_mapping(before_map, data->stack_a.stack, size);
	data->stack_a.bottom = size;
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

int    check_val(char *str)
{
    long long   num;
    int         sign;

    num = 0;
    sign = 1;
    if (*str == '\0')
        return (0);
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    if (*str == '\0')
        return (0);
    while (*str)
    {   
        if (!(*str >= '0' && *str <= '9'))
            return (0);
        num = num * 10 + (*str - '0');
        if ((sign == 1 && num > INT_MAX) || (sign == -1 && -num < INT_MIN))
            return (0);
        str++;
    }
    return (1);
}



int	check_dup(int size, int *arr)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] == arr[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

void    rank_mapping(int *value, int *mapping, int size)
{
    int	i;
	int j;
	int	count;

	i = 0;
	while (i < size)
	{	
		count = 0;
		j = 0;
		while(j < size)
		{
			if (value[i] > value[j])
				count++;
			j++;
		}
		mapping[i] = count;
		i++;
	}
}

void    handle_error(t_data *data)
{
    write(2, "Error\n", 6);
    free(data->stack_a.stack);
    free(data->stack_b.stack);
    exit(1);
}


int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}