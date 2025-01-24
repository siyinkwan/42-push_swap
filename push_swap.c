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


#include <stdio.h> //TO REMOVE

int main(int argc, char **argv)
{
    if (argc == 1)
        return (0);
    t_node *head_a;
    t_node *current_a;
    t_node *head_b;

    head_a = get_stack(argv);
    head_b = NULL;
    current_a = head_a;

    printf("%s","original stack a:\n");
    while (current_a != NULL)
    {
        printf("%d\n",current_a->value);
        current_a = current_a->next;
    }

    sa(&head_a);
    current_a = head_a;
    printf("%s","stack a after sa:\n");
    while (current_a != NULL)
    {
    printf("%d\n",current_a->value);
    current_a = current_a->next;
    }
}
