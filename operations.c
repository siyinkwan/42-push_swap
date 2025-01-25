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

void    push(t_node **head1, t_node **head2)
{
    if (*head1 == NULL)
        return;
    
    t_node *temp;

    temp = (*head1)->next;
    (*head1)->next = *head2;
    *head2 = *head1;
    (*head1) = temp;
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

void    pa(t_node **head_b, t_node **head_a)
{
    push(head_b, head_a);
}

void    pb(t_node **head_a, t_node **head_b)
{
    push(head_a, head_b);
}