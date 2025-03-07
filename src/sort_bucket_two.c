/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bucket_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:58:33 by sguan             #+#    #+#             */
/*   Updated: 2025/03/07 21:09:48 by sguan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_data *data, t_bucket *bucket)
{
	if (bucket->pos == 1)
	{
		rra(&data->stack_a);
		rra(&data->stack_a);
	}
	else if (bucket->pos == 2)
	{
		pa(&data->stack_b, &data->stack_a);
		pa(&data->stack_b, &data->stack_a);
	}
	else if (bucket->pos == 3)
	{
		rrb(&data->stack_b);
		rrb(&data->stack_b);
		pa(&data->stack_b, &data->stack_a);
		pa(&data->stack_b, &data->stack_a);
	}
	sort_two_a(&data->stack_a);
	bucket->size = bucket->size - 2;
}
