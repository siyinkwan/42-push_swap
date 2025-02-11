#include "push_swap.h"
#include <stdio.h>
#include <stdio.h>

//int count = 0; 

int main(int argc, char **argv)
{
    if (argc < 2)
        return (0);
    t_stack *stack_a;
    t_stack *stack_b = malloc(sizeof(t_stack));
    stack_a = get_stack(argv);

    if (!stack_a || !stack_b)
        return (-1);
    
    sort_stack(stack_a, stack_b);
    
    free(stack_b);
    free(stack_a);
    return (0);
}