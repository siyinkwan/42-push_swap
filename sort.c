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


#include <stdio.h>
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

#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc == 1)
        return (0);
    t_stack *test;
    t_stack *stack_b = malloc(sizeof(t_stack));
    test = get_stack(argv);
    // printf("stack test:\n");
    // print_stack(test);
    // printf("\nstack b:\n");
    // print_stack(stack_b);
    if (!is_sorted(test))
        sort_five(test, stack_b);
    // printf("\n-------------------------------\n");
    // //printf("\nis sorted: %d",is_sorted(test));
    // printf("\nnew stack test:\n");
    // print_stack(test);
    // printf("\nnew stack b:\n");
    // print_stack(stack_b);
    //printf("\nmin: %d", get_min(test));
}