#ifndef H_PUSH
# define H_push

#include <stdlib.h>

typedef struct s_node{
    int value;
    struct s_node *next;
} t_node;

void    sa(t_node **head_a);
void    sb(t_node **head_b);
void    ss(t_node **head_a, t_node **head_b);
void    pb(t_node **head_a, t_node **head_b);
void    pa(t_node **head_b, t_node **head_a);



#endif