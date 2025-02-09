#include "push_swap.h"
#include <stdio.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc == 1)
        return (0);
    t_stack *stack_a;
    t_stack *stack_b = malloc(sizeof(t_stack));
    stack_a = get_stack(argv);

    // printf("Initial stack (a):\n");
    // print_stack(stack_a);
    // printf("\nInitial stack (b):\n");
    // print_stack(stack_b);

    if (!is_sorted(stack_a) && argc == 6)
        sort_five(stack_a, stack_b);
    
    if (!is_sorted(stack_a) && argc == 6)
        
    // printf("\nStack (a) after sorting:\n");
    // print_stack(stack_a);
    // printf("\nIs stack_a sorted after sorting? %s\n", is_sorted(stack_a) ? "Yes" : "No");

    // free(stack_b);
    // free(stack_a);


    // split_stack_a(stack_a, stack_b);
    // printf("\nafter split_stack_a a:\n");
    // print_stack(stack_a);
    // printf("\nafter split_stack_a a:\n");  
    // print_stack(stack_b);  


    // split_stack_b(stack_a, stack_b);
    // printf("\nafter split_stack_b a:\n");
    // print_stack(stack_a); 
    // printf("\nafter split_stack_b b:\n");
    // print_stack(stack_b);  

    return (0);
}