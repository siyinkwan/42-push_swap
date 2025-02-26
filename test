#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

void    rank_mapping(int *data, int *mapping, int size)
{
    int	i;
	int j;
	int	count;

	i = 0;
	while (i < size)
	{
		while(j < size)
		{
			count = 0;
			j = 0;
			if (data[i] > data[j])
				count++;
			j++;
		}
		mapping[i] = count;
		i++;
	}
}


//TEST DATA MAPPING
// int	main(int argc, char **argv)
// {
// 	if (argc < 2)
// 	{
// 		printf("Usage: ./program number1 number2 ...\n");
// 		return (1);
// 	}

// 	int *number = malloc((argc - 1) * sizeof(int));
// 	int *rank = malloc((argc - 1) * sizeof(int));

// 	if (!number || !rank)
// 	{
// 		printf("Memory allocation failed\n");
// 		return (1);
// 	}

// 	for (int i = 1; i < argc; i++)
// 		number[i - 1] = atoi(argv[i]);

// 	printf("Before Mapping:\n");
// 	for (int i = 0; i < argc - 1; i++)
// 		printf("%d ", number[i]);
// 	printf("\n");
// 	random_to_rank(number, rank, argc - 1);

// 	printf("After Mapping:\n");
// 	for (int i = 0; i < argc - 1; i++)
// 		printf("%d ", rank[i]);
// 	printf("\n");


// 	free(number);
// 	free(rank);

// 	return (0);
// }


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

///////////////


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
