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


#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc == 1)
        return (0);
    t_stack *test;
    //t_stack *stack_b = malloc(sizeof(t_stack));
    test = get_stack(argv);
    printf("stack test:\n");
    print_stack(test);
    // printf("\nstack b:\n");
    // print_stack(stack_b);
    if (!is_sorted(test))
        sort_three(test);
    printf("\n-------------------------------\n");
    //printf("\nis sorted: %d",is_sorted(test));
    printf("new stack test:\n");
    print_stack(test);
    // printf("\nnew stack b:\n");
    // print_stack(stack_b);
}