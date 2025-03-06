/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:02:53 by sguan             #+#    #+#             */
/*   Updated: 2025/03/06 23:00:59 by sguan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data	data;
	char	**arr;
	int		size;
	
	if (argc == 2)
	{
		arr = ft_split(argv[1]);
		size = word_count(argv[1]);
	}
	else
	{
		arr = argv + 1;
		size = argc - 1;
	}
	get_stack(&data, size, arr);
	sort_stack(&data);
	if (argc == 2)
	{
		int i = 0;
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
	if (data.stack_a.stack)
		free(data.stack_a.stack);
	if (data.stack_b.stack)
		free(data.stack_b.stack);
	exit(0);
}

