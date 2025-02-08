#include "push_swap.h"
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
}

void    sb(t_stack *stack_b)
{
    swap(stack_b);
    op_count++;
}

void    ss(t_stack *stack_a, t_stack *stack_b)
{
    swap(stack_a);
    swap(stack_b);
    op_count++;
}

void    pa(t_stack *stack_b, t_stack *stack_a)
{
    push(stack_b, stack_a);
    op_count++;
}

void    pb(t_stack *stack_a, t_stack *stack_b)
{
    push(stack_a, stack_b);
    op_count++;
}

void    ra(t_stack *stack_a)
{
    rotate(stack_a);
    op_count++;
}

void    rb(t_stack *stack_b)
{
    rotate(stack_b);
    op_count++;
}

void    rr(t_stack *stack_a, t_stack *stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    op_count++;
}

void    rra(t_stack *stack_a)
{
    r_rotate(stack_a);
    op_count++;
}

void    rrb(t_stack *stack_b)
{
    r_rotate(stack_b);
    op_count++;
}

void    rrr(t_stack *stack_a, t_stack *stack_b)
{
    r_rotate(stack_a);
    r_rotate(stack_b);
    op_count++;
}