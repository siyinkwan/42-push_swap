/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:56:59 by sguan             #+#    #+#             */
/*   Updated: 2025/03/07 14:45:09 by sguan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->stack[get_next_index(stack, stack->top)] == 0)
		return ;
	tmp = stack->stack[get_next_index(stack, stack->top)];
	stack->stack[get_next_index(stack, stack->top)] = stack->stack[stack->top];
	stack->stack[stack->top] = tmp;
}

void	push(t_stack *src, t_stack *dest)
{
	int	dest_i;

	if (dest->size == length(dest))
		return ;
	dest_i = get_previous_index(dest, dest->top);
	dest->stack[dest_i] = src->stack[src->top];
	dest->top = dest_i;
	src->stack[src->top] = 0;
	src->top = get_next_index(src, src->top);
}

void	rotate(t_stack *stack)
{
	if (stack->size == length(stack))
	{
		stack->bottom = stack->top;
		stack->top = get_next_index(stack, stack->top);
	}
	else
	{
		stack->bottom = get_next_index(stack, stack->bottom);
		stack->stack[stack->bottom] = stack->stack[stack->top];
		stack->stack[stack->top] = 0;
		stack->top = get_next_index(stack, stack->top);
	}
}

void	r_rotate(t_stack *stack)
{
	if (stack->size == length(stack))
	{
		stack->top = stack->bottom;
		stack->bottom = get_previous_index(stack, stack->bottom);
	}
	else
	{
		stack->top = get_previous_index(stack, stack->top);
		stack->stack[stack->top] = stack->stack[stack->bottom];
		stack->stack[stack->bottom] = 0;
		stack->bottom = get_previous_index(stack, stack->bottom);
	}
}
