/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:09:38 by sguan             #+#    #+#             */
/*   Updated: 2025/03/07 13:37:54 by sguan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_val(char *str)
{
	long long	num;
	int			sign;

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
		if ((sign == 1 && (num > INT_MAX)) || (sign == -1 && (-num < INT_MIN)))
			return (0);
		str++;
	}
	return (1);
}

int	check_dup(int size, int *arr)
{
	int	i;
	int	j;

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

void	rank_mapping(int *value, int *mapping, int size)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < size)
	{	
		count = 0;
		j = 0;
		while (j < size)
		{
			if (value[i] > value[j])
				count++;
			j++;
		}
		mapping[i] = count + 1;
		i++;
	}
}

int	get_nth_value(t_stack *stack, int n, bool from_top)
{
	int	i;

	if (stack == NULL || n <= 0 || length(stack) < n)
		return (-1);

	else if (from_top)
		i = stack->top;
	else if (!from_top)
		i = stack->bottom;
	while (n > 1)
	{
		if (from_top)
			i = get_next_index(stack, i);
		else
			i = get_previous_index(stack, i);
		n--;
	}
	return (stack->stack[i]);
}
