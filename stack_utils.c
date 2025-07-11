#include "push_swap.h"

t_stack    *get_stack(char **arr)
{
    int i;
    t_stack *stack = malloc(sizeof(t_stack));

    if (!stack)
        return (NULL);
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;

    i = 1;
    while (arr[i])
    {
        t_node *node = malloc(sizeof(t_node));
        if (!node)
            return (NULL); 
        node->value = atoi(arr[i]);        //change to ft_atoi
        node->next = NULL;
        if (stack->top == NULL)
        {
            stack->top = node;
            stack->bottom = node;
        }
        else
        {
            stack->bottom->next = node; 
            stack->bottom = node;
        }
        stack->size++;    
        i++;
    }
    return (stack);
}

void    check_int()
{

}

void	check_duplication()
{

}

void    free_stacks()
{

}

void    handle_error()
{
    
}


// FOR TESTING:
#include <stdio.h>

void    print_stack(t_stack *stack)
{
    t_node *current;

    current = stack->top;
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
    //printf("\nstack size: %d",stack->size);
}

t_node    *create_node(int value)
{
    t_node *new_node; 
    
    new_node = malloc(sizeof(t_node));
    new_node->value = value;
    new_node->next = NULL;
    return(new_node);
}















////////////////////TESTING SCRIPT///////////////////////////////////////
    // head_b = create_node(10);
    // head_b->next = create_node(42);

    //test swap
    // printf("%s","original stack a:\n");
    // print_stack(head_a);
    // sa(&head_a);
    // printf("%s","stack a after sa:\n");
    // print_stack(head_a);

    //test push
    // printf("%s","original stack a:\n");
    // print_stack(head_a);
    // printf("%s","original stack b:\n");
    // print_stack(head_b);
    // pa(&head_b, &head_a);
    // printf("\n\n%s","stack a after pb:\n");
    // print_stack(head_a);
    // printf("%s","stack b after pb:\n");
    // print_stack(head_b);

    //test reverse
    // printf("%s","original stack a:\n");
    // print_stack(head_a);
    // rra(&head_a);
    // printf("%s","stack a after rra:\n");
    // print_stack(head_a);