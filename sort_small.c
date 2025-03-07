/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:03:16 by sguan             #+#    #+#             */
/*   Updated: 2025/03/07 14:15:50 by sguan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_a(t_stack *stack_a)
{
	int	first;
	int	second;

	first = get_nth_value(stack_a, 1, 1);
	second = get_nth_value(stack_a, 2, 1);
	if (first > second)
		sa(stack_a);
	return ;
}

void	sort_three_a(t_stack *stack_a)
{
	int	top;
	int	mid;
	int	bot;

	top = get_nth_value(stack_a, 1, 1);
	mid = get_nth_value(stack_a, 2, 1);
	bot = get_nth_value(stack_a, 3, 1);
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