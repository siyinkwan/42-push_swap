#include "push_swap.h"

void    sort_two(t_stack *stack)
{
    if (is_sorted(stack))
        return;
    if (stack->top->value > stack->bottom->value)
        sa(stack);
}

void    sort_three(t_stack *stack)
{
    if (is_sorted(stack))
        return;
    int top = stack->top->value;
    int mid = stack->top->next->value;
    int bot = stack->bottom->value;

    if (top < mid && top < bot && mid > bot) // A C B
    {
        sa(stack);
        ra(stack);
    }
    else if (top > mid && top < bot && mid < bot) // B A C
        sa(stack);
    else if (top < mid && top > bot && mid > bot) // B C A
        rra(stack);
    else if (top > mid && top > bot && mid < bot) // C A B
        ra(stack);
    else if (top > mid && top > bot && mid > bot) // C B A
    {
        ra(stack);
        sa(stack);
    }
}

void    sort_five(t_stack *stack_a, t_stack *stack_b)
{
    if (is_sorted(stack_a))
        return;
    push_min(stack_a, stack_b, 1);
    push_min(stack_a, stack_b, 0);
    sort_three(stack_a);
    pa(stack_b, stack_a);
    pa(stack_b, stack_a);
}

