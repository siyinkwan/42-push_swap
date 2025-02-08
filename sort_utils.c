#include "push_swap.h"

int    is_sorted(t_stack *stack)
{
    t_node  *current;

    current = stack->top;
    if (!current || stack->size <= 1)
        return (1);
    while (current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}

int    get_min(t_stack *stack)
{
    if (!stack || !stack->top)
        return (-1);

    t_node  *current;
    t_node  *min;
    int min_index;
    int i;

    current = stack->top;
    min = stack->top;
    min_index = 0;
    i = 0;

    while (current)
    {
        if (current->value < min->value)
        {
            min = current;
            min_index = i;
        }
        current = current->next;
        i++;
    }
    return (min_index);
}

void    push_min(t_stack *stack_a, t_stack *stack_b, int first_push)
{
    int min_index;

    min_index = get_min(stack_a);
    if (min_index == 1)
        sa(stack_a);
    else if (min_index == 2)
    {
        if (first_push)
        {
            ra(stack_a);
            ra(stack_a);
        }
        else
        {
            rra(stack_a);
            rra(stack_a);
        }
    }
    else if (min_index == 3)
    {
        rra(stack_a);
        if (first_push)
            rra(stack_a);
    }
    else if (min_index == 4)
        rra(stack_a);
    pb(stack_a, stack_b);
}