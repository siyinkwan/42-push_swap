/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:45:24 by sguan             #+#    #+#             */
/*   Updated: 2025/03/07 15:05:11 by sguan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sa(t_stack *stack_a)
{
	swap(stack_a);
	printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
    swap(stack_b);
    
    printf("ss\n");
}

void    pa(t_stack *stack_b, t_stack *stack_a)
{
    push(stack_b, stack_a);
    
    printf("pa\n");
}

void    pb(t_stack *stack_a, t_stack *stack_b)
{
    push(stack_a, stack_b);
    
    printf("pb\n");
}

void    ra(t_stack *stack_a)
{
    rotate(stack_a);
    
    printf("ra\n");
}

void    rb(t_stack *stack_b)
{
    rotate(stack_b);
    
    printf("rb\n");
}

void    rr(t_stack *stack_a, t_stack *stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    
    printf("rr\n");
}

void    rra(t_stack *stack_a)
{
    r_rotate(stack_a);
    
    printf("rra\n");
}

void    rrb(t_stack *stack_b)
{
    r_rotate(stack_b);
    
    printf("rrb\n");
}

void    rrr(t_stack *stack_a, t_stack *stack_b)
{
    r_rotate(stack_a);
    r_rotate(stack_b);
    
    printf("rrr\n");
}