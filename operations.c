#include "push_swap.h"

void    swap(t_node **head)
{
    if (*head == NULL || ((*head)->next == NULL))
        return;

    t_node  *second;

    second = (*head)->next;
    (*head)->next = second->next;
    second->next = *head;
    *head = second;
}

void    push(t_node **head)
{
//TODO
}





void    sa(t_node **head_a)
{
    swap(head_a);
}

void    sb(t_node **head_b)
{
    swap(head_b);
}

void    ss(t_node **head_a, t_node **head_b)
{
    swap(head_a);
    swap(head_b);
}
