/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:09:46 by sguan             #+#    #+#             */
/*   Updated: 2025/03/07 13:38:26 by sguan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_stack(t_data *data, int size, char **arr)
{
	int	i;
	int	*before_map;

	pre_get_stack(data, &data->stack_a, size);
	pre_get_stack(data, &data->stack_b, size);
	before_map = malloc(sizeof(int) * size);
	if (!before_map)
		handle_error(data, before_map, arr, size);
	i = 0;
	while (arr[i])
	{
		if (!check_val(arr[i]))
			handle_error(data, before_map, arr, size);
		before_map[i] = ft_atoi(arr[i]);
		i++;
	}
	if (check_dup(size, before_map))
		handle_error(data, before_map, arr, size);
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
	{
		if (data->stack_a.stack)
			free(data->stack_a.stack);
		if (data->stack_b.stack)
			free(data->stack_b.stack);
		return ;
	}
	pre_stack->top = 0;
	pre_stack->bottom = 0;
	pre_stack->size = size;
	while (i < size)
	{
		pre_stack->stack[i] = 0;
		i++;
	}
}

void	handle_error(t_data *data, int *before_map, char **arr, int size)
{
	free(before_map);
	free_all(data, arr, size);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_all(t_data *data, char **arr, int size)
{
	int	i;

	if (size == 1)
	{
		i = 0;
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
	if (data->stack_a.stack)
		free(data->stack_a.stack);
	if (data->stack_b.stack)
		free(data->stack_b.stack);
}
