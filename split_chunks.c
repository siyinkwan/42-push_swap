#include "push_swap.h"

void    split_stack_a(t_stack *stack_a, t_stack *stack_b, int *pivot_min, int *pivot_max)
{
    int i;
    int original_size;
    t_node  *current;

    i = 0;
    current = stack_a->top;
    original_size = stack_a->size;
    get_pivots(stack_a, &pivot_min, &pivot_max);
    while(i < original_size)
    {
        if (current->value < pivot_min)
        {
            current = current->next;
            pb(stack_a, stack_b);
            if (stack_b->size != 0)
                rb(stack_b);
        }
        else if (current->value >= pivot_min && current->value < pivot_max)
        {
            current = current->next;
            pb(stack_a, stack_b);
        }
        else if (current->value >= pivot_max)
        {
            current = current->next;
            ra(stack_a);
        }
        i++;
    }
}

void    split_stack_b(t_stack *stack_a, t_stack *stack_b, int *pivot_min, int *pivot_max)
{
    if (stack_b->size <= 3)
    {
        sort_small_stack_b(stack_b);
        while (stack_b->size > 0)
            pa(stack_b, stack_a);
    }

    int i;
    int original_size;
    t_node  *current;

    i = 0;
    current = stack_b->top;
    original_size = stack_b->size;
    get_pivots(stack_b, &pivot_min, &pivot_max);
    while(i < original_size)
    {
        if (current->value > pivot_max)
        {
            current = current->next;
            pa(stack_b, stack_a);
        }
        else
        {
            current = current->next;
            rb(stack_b);
        }
        i++;
    }
}