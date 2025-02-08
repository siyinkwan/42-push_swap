#include "push_swap.h"

int    get_middle_value(t_stack *stack)
{
    int i;
    t_node  *current;

    i = 0;
    current = stack->top;
    while (i < stack->size / 2)
    {
        current = current->next;
        i++;
    }
    return (current->value);
}

void    get_pivots(t_stack *stack, int *pivot_min, int *pivot_max)
{
    int first;
    int middle;
    int last;

    first = stack->top->value;
    middle = get_middle_value(stack);
    last = stack->bottom->value;
    if((first <= middle && first >= last) || (first >= middle && first <= last)) //try to use XOR to compare the speed
    {
        *pivot_min = first;
        if (middle <= last)
            *pivot_max = last;
        else if ((middle > last))
            *pivot_max = middle;
    }
    if((first < middle && middle < last) || (first > middle && middle > last))
    {
        *pivot_min = middle;
        if(first <= last)
            *pivot_max = last;
        else if ((first > last))
            *pivot_max = first;
    }
    if((last < middle && first < last) || (last > middle && first > last))
    {
        *pivot_min = last;
        if(first <= middle)
            *pivot_max = middle;
        else if ((first > middle))
            *pivot_max = first;
    }     
}

void    sort_small_stack_b(t_stack *stack_b)
{
    if (stack_b->size == 0 || stack_b->size == 1)
        return ;
    if (stack_b->size == 2)
        sort_two(stack_b);
    if (stack_b->size == 3)
        sort_three(stack_b);
}

