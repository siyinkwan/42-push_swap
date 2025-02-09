#include "push_swap.h"
#include <stdio.h>

int op_count = 0;

void    swap(t_stack *stack)
{
    if (stack->size < 2)
        return;

    t_node  *second;

    second = stack->top->next;
    stack->top->next = second->next;
    second->next = stack->top;
    stack->top = second;
}

void    push(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->top == NULL)
        return;
    
    t_node *temp;

    temp = stack_a->top;
    stack_a->top = stack_a->top->next;
    if (stack_a->top == NULL)
        stack_a->bottom = NULL;
    temp->next = stack_b->top;
    stack_b->top = temp;
    if (stack_b->bottom == NULL)
        stack_b->bottom = temp;
    stack_a->size--;
    stack_b->size++;
}

void    rotate(t_stack *stack)
{
    if (stack->size < 2)
        return;

    t_node  *first;
    t_node  *current;

    first = stack->top;
    current = stack->top;
    stack->top = stack->top->next;
    while (current->next != NULL)
        current = current->next;
    first->next = NULL;
    current->next = first;
    stack->bottom = first;
}

void    r_rotate(t_stack *stack)
{
    if (stack->size < 2)
        return;

    t_node  *current;
    t_node  *prev;

    current = stack->top;
    prev = NULL;
    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    current->next = stack->top;
    stack->top = current;
    stack->bottom = prev;
}

void    sa(t_stack *stack_a)
{
    swap(stack_a);
    op_count++;
    printf("sa\n");
}

void    sb(t_stack *stack_b)
{
    swap(stack_b);
    op_count++;
    printf("sb\n");
}

void    ss(t_stack *stack_a, t_stack *stack_b)
{
    swap(stack_a);
    swap(stack_b);
    op_count++;
    printf("ss\n");
}

void    pa(t_stack *stack_b, t_stack *stack_a)
{
    push(stack_b, stack_a);
    op_count++;
    printf("pa\n");
}

void    pb(t_stack *stack_a, t_stack *stack_b)
{
    push(stack_a, stack_b);
    op_count++;
    printf("pb\n");
}

void    ra(t_stack *stack_a)
{
    rotate(stack_a);
    op_count++;
    printf("ra\n");
}

void    rb(t_stack *stack_b)
{
    rotate(stack_b);
    op_count++;
    printf("rb\n");
}

void    rr(t_stack *stack_a, t_stack *stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    op_count++;
    printf("rr\n");
}

void    rra(t_stack *stack_a)
{
    r_rotate(stack_a);
    op_count++;
    printf("rra\n");
}

void    rrb(t_stack *stack_b)
{
    r_rotate(stack_b);
    op_count++;
    printf("rrb\n");
}

void    rrr(t_stack *stack_a, t_stack *stack_b)
{
    r_rotate(stack_a);
    r_rotate(stack_b);
    op_count++;
    printf("rrr\n");
}