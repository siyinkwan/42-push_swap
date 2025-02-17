//add header

#include "push_swap.h"
#include <stdio.h>

// void	swap(t_stack *stack)
// {
// 	int	temp;

// 	if (stack->size < 2)
// 		return;
// 	temp = stack->stack[stack->top];
// 	stack->stack[stack->top] = stack->stack[stack->top + 1];
// 	stack->stack[stack->top + 1] = temp;
// }

/// TO rewrite
void	swap(t_stack *stk)
{
	int	tmp;

	if (stk->stack[next_down(stk, stk->top)] == 0)
		return ;
	tmp = stk->stack[next_down(stk, stk->top)];
	stk->stack[next_down(stk, stk->top)] = stk->stack[stk->top];
	stk->stack[stk->top] = tmp;
}

void	push(t_stack *src, t_stack *dest)
{
	int	dest_i;

	if (dest->size == length(dest))
		return ;
	dest_i = next_up(dest, dest->top);
	dest->stack[dest_i] = src->stack[src->top];
	dest->top = dest_i;
	src->stack[src->top] = 0;
	src->top = next_down(src, src->top);
}

void	rotate(t_stack *stk)
{
	if (stk->size == length(stk))
	{
		stk->bottom = stk->top;
		stk->top = next_down(stk, stk->top);
	}
	else
	{
		stk->bottom = next_down(stk, stk->bottom);
		stk->stack[stk->bottom] = stk->stack[stk->top];
		stk->stack[stk->top] = 0;
		stk->top = next_down(stk, stk->top);
	}
}

void	r_rotate(t_stack *stk)
{
	if (stk->size == length(stk))
	{
		stk->top = stk->bottom;
		stk->bottom = next_up(stk, stk->bottom);
	}
	else
	{
		stk->top = next_up(stk, stk->top);
		stk->stack[stk->top] = stk->stack[stk->bottom];
		stk->stack[stk->bottom] = 0;
		stk->bottom = next_up(stk, stk->bottom);
	}
}

int	next_up(t_stack *stk, int index)
{
	if (length(stk) == 0)
		return (index);
	if (index == 0)
		return (stk->size - 1);
	else
		return (index - 1);
}

int	next_down(t_stack *stk, int index)
{
	if (length(stk) == 0)
		return (index);
	if (index == stk->size - 1)
		return (0);
	else
		return (index + 1);
}

// int	value(t_stack *stk, int n)
// {
// 	int	i;

// 	i = stk->top;
// 	while (--n > 0)
// 		i = next_down(stk, i);
// 	return (stk->stack[i]);
// }


int	length(t_stack *stk)
{
	if (stk->top == stk->bottom && stk->stack[stk->top] == 0)
		return (0);
	if (stk->top > stk->bottom)
		return ((stk->size - stk->top) + (stk->bottom + 1));
	else
		return (stk->bottom - stk->top + 1);
}

void    sa(t_stack *stack_a)
{
    swap(stack_a);
    
    printf("sa\n");   //change to ft_printf
}

void    sb(t_stack *stack_b)
{
    swap(stack_b);
    
    printf("sb\n");
}

void    ss(t_stack *stack_a, t_stack *stack_b)
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

