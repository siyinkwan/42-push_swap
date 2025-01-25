#include "push_swap.h"

t_node    *get_stack(char **arr)
{
    int i;
    t_node *head = NULL;
    t_node *current = NULL;

    i = 1;
    while (arr[i])
    {
        t_node *node = malloc(sizeof(t_node));  
        node->value = atoi(arr[i]);

        if (head == NULL)
        {
            head = node;
            current = node;
        }
        else
        {
            current->next = node; 
            current = node;
        }    
        i++;
    }
    return (head);
}

// FOR TESTING:
#include <stdio.h>

void    print_stack(t_node *head)
{
    t_node *current;

    current = head;
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}

t_node    *create_node(int value)
{
    t_node *new_node; 
    
    new_node = malloc(sizeof(t_node));
    new_node->value = value;
    new_node->next = NULL;
    return(new_node);
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return (0);
    t_node *head_a;
    t_node *head_b;

    head_a = get_stack(argv);
    //head_b = NULL;
    head_b = create_node(10);
    head_b->next = create_node(42);

    //test swap
    // printf("%s","original stack a:\n");
    // print_stack(head_a);
    // sa(&head_a);
    // printf("%s","stack a after sa:\n");
    // print_stack(head_a);

    //test push
    printf("%s","original stack a:\n");
    print_stack(head_a);
    printf("%s","original stack b:\n");
    print_stack(head_b);
    pa(&head_b, &head_a);
    printf("\n\n%s","stack a after pb:\n");
    print_stack(head_a);
    printf("%s","stack b after pb:\n");
    print_stack(head_b);

    //rest reverse
    
}
