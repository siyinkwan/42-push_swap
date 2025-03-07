/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:02:53 by sguan             #+#    #+#             */
/*   Updated: 2025/03/07 13:33:13 by sguan            ###   ########.fr       */
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
	free_all(&data, arr, size);
	exit(0);
}

