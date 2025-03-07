/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:56:59 by sguan             #+#    #+#             */
/*   Updated: 2025/03/07 23:38:19 by sguan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->stack[get_next_index(stack, stack->top)] == 0)
		return ;
	temp = stack->stack[get_next_index(stack, stack->top)];
	stack->stack[get_next_index(stack, stack->top)] = stack->stack[stack->top];
	stack->stack[stack->top] = temp;
}

void	push(t_stack *from, t_stack *to)
{
	int	dest_i;

	if (to->size == length(to))
		return ;
	dest_i = get_previous_index(to, to->top);
	to->stack[dest_i] = from->stack[from->top];
	to->top = dest_i;
	from->stack[from->top] = 0;
	from->top = get_next_index(from, from->top);
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

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
	ft_printf("rrr\n");
}
