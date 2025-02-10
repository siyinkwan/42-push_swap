#include "push_swap.h"

void    sort_two(t_stack *stack)
{
    if (stack->top->value > stack->bottom->value)
        sa(stack);
}

void    sort_three(t_stack *stack)
{
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
    push_min(stack_a, stack_b, 1);
    push_min(stack_a, stack_b, 0);
    sort_three(stack_a);
    pa(stack_b, stack_a);
    pa(stack_b, stack_a);
}

void    recursive_sort_a(t_stack *stack_a, t_stack *stack_b)
{
    if (is_sorted(stack_a))
        return;
    if (stack_a->size <= 5)
    {
        if (stack_a->size <= 1)
            return;
        else if (stack_a->size == 2)
            sort_two(stack_a);
        else if (stack_a->size == 3)
            sort_three(stack_a);
        else if (stack_a->size == 5)
            sort_five(stack_a, stack_b);
        return;
    }
    else
    { 
        split_stack_a(stack_a, stack_b);
        recursive_sort_a(stack_a, stack_b);
    }
    recursive_sort_b(stack_a, stack_b);
    while (stack_b->size > 0)
        pa(stack_b, stack_a);
}
void    recursive_sort_b(t_stack *stack_a, t_stack *stack_b)
{
    if (is_sorted(stack_b))
        return;
    if (stack_b->size <= 5)
    {
        if (stack_b->size <= 1)
            return;
        else if (stack_b->size == 2)
            sort_two(stack_b);
        else if (stack_b->size == 3)
            sort_three(stack_b);
        else if (stack_b->size == 5)
        //todo: add sort 4 
            sort_five(stack_a, stack_b);
        return;
    }
    else
    {
        split_stack_b(stack_a, stack_b);
        recursive_sort_b(stack_a, stack_b);
    }
    // while (stack_b->size > 0)
    //     pa(stack_b, stack_a);
}

void    sort_stack(t_stack *stack_a, t_stack *stack_b)
{
    if (is_sorted(stack_a))
        return;
    else if (stack_a->size <= 1)
        return;
    else if (stack_a->size == 2)
        sort_two(stack_a);
    else if (stack_a->size == 3)
        sort_three(stack_a);
    else if (stack_a->size == 5)
        sort_five(stack_a, stack_b);
    else
        recursive_sort_a(stack_a, stack_b);
}