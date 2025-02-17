#include "push_swap.h"

void    split_stack_a(t_stack *stack_a, t_stack *stack_b, int *count)
{
    if (stack_a == NULL || stack_a->size < 2)
        return;
    int i;
    int original_size;
    int pivot_min;
    int pivot_max; 
    //t_node  *current;

    i = 0;
    get_pivots_a(stack_a, &pivot_min, &pivot_max);
    //current = stack_a->top;
    original_size = stack_a->size;
    while(i < original_size)
    {
        if (stack_a->top->value < pivot_min)
        {
            //current = current->next;
            pb(stack_a, stack_b);
           (*count)--;
            if (stack_b->size > 1)
                rb(stack_b);
        }
        else if (stack_a->top->value >= pivot_min && stack_a->top->value < pivot_max)
        {
            //current = current->next;
            pb(stack_a, stack_b);
            (*count)--;
        }
        else
        {
            //current = current->next;
            ra(stack_a);
        }
        i++;
        // if (stack_a->size == 0)
        //     break;
    }
}

void    split_stack_b(t_stack *stack_a, t_stack *stack_b, int *count)
{
    if (stack_b == NULL || stack_b->size < 2)
        return;

    int i;
    int original_size;
    int pivot_min;
    int pivot_max; 
    //t_node  *current;

    i = 0;
    //current = stack_b->top;
    get_pivots_b(stack_b, &pivot_min, &pivot_max);
    original_size = stack_b->size;
    while(i < original_size)
    {
        if (stack_b->top->value > pivot_max)
        {
            //current = current->next;
            pa(stack_b, stack_a);
             (*count)++;
            // if (stack_a->size > 1)
            //     ra(stack_a);
        }
        else if (stack_b->top->value >= pivot_min && stack_b->top->value <= pivot_max)
        {
            pa(stack_b, stack_a); 
             (*count)++;
        }
        else if (stack_b->top->value < pivot_min)
        {
            //current = current->next;
            rb(stack_b);
        }
        i++;
    }
}