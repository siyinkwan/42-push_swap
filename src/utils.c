/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:59:49 by sguan             #+#    #+#             */
/*   Updated: 2025/03/07 15:02:29 by sguan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_previous_index(t_stack *stack, int index)
{
	if (length(stack) == 0)
		return (index);
	if (index == 0)
		return (stack->size - 1);
	else
		return (index - 1);
}

int	get_next_index(t_stack *stack, int index)
{
	if (length(stack) == 0)
		return (index);
	if (index == stack->size - 1)
		return (0);
	else
		return (index + 1);
}

int	length(t_stack *stack)
{
	if (stack->top == stack->bottom && stack->stack[stack->top] == 0)
		return (0);
	if (stack->top > stack->bottom)
		return ((stack->size - stack->top) + (stack->bottom + 1));
	else
		return (stack->bottom - stack->top + 1);
}
