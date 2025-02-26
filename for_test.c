#include "push_swap.h"

void print_stack_1(t_stack *stack)
{
    printf("Stack (size: %d, top index: %d, bottom index: %d):\n", 
           stack->size, stack->top, stack->bottom);
    
    for (int i = 0; i < stack->size; i++)
    {
        int index = (stack->top + i) % stack->size;
        printf("[%d]: %d ", index, stack->stack[index]);
    }
    printf("\n");
}



void print_stack_2(int *stack, int size)
{
    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("]\n");
}

// int main()
// {
//     t_stack stack_a;
//     int arr[2] = {6, 4};
//     stack_a.stack = arr;
//     stack_a.top = 0;
//     stack_a.bottom = 1;
//     stack_a.size = 2;

//     printf("Before sorting:\n");
//     print_stack_1(&stack_a);

//     sa(&stack_a);

//     printf("After sorting:\n");
//     print_stack_1(&stack_a);
// }



// int	main(int argc, char **argv)
// {

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
// 	rank_mapping(number, rank, argc - 1);

// 	printf("After Mapping:\n");
// 	for (int i = 0; i < argc - 1; i++)
// 		printf("%d ", rank[i]);
// 	printf("\n");


// 	free(number);
// 	free(rank);

// 	return (0);
// }