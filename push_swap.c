#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc == 1)
        return (0);
    t_stack *test;
    t_stack *stack_b = malloc(sizeof(t_stack));
    test = get_stack(argv);
    printf("stack test:\n");
    print_stack(test);
    printf("\nstack b:\n");
    print_stack(stack_b);
    // if (!is_sorted(test))
    //     sort_five(test, stack_b);
    split_stack(test, stack_b);
    // printf("\n-------------------------------\n");
    // //printf("\nis sorted: %d",is_sorted(test));
    printf("\nnew stack test:\n");
    print_stack(test);
    printf("\nnew stack b:\n");
    print_stack(stack_b);
    printf("\nOPERATIONS: %d", op_count);
}