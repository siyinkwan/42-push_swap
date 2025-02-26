#include "push_swap.h"
#include <stdio.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data	data;

    get_stack(&data, argc, argv);
	sort_stack(&data);
    free(data.stack_a.stack);
    free(data.stack_b.stack);
	exit(0);
}

