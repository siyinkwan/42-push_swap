/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:09:38 by sguan             #+#    #+#             */
/*   Updated: 2025/03/06 23:25:19 by sguan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    check_val(char *str)
{
    long long   num;
    int         sign;

    num = 0;
    sign = 1;
    if (*str == '\0')
        return (0);
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    if (*str == '\0')
        return (0);
    while (*str)
    {   
        if (!(*str >= '0' && *str <= '9'))
            return (0);
        num = num * 10 + (*str - '0');
        if ((sign == 1 && num > INT_MAX) || (sign == -1 && -num < INT_MIN))
            return (0);
        str++;
    }
    return (1);
}

int	check_dup(int size, int *arr)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] == arr[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

void    rank_mapping(int *value, int *mapping, int size)
{
    int	i;
	int j;
	int	count;

	i = 0;
	while (i < size)
	{	
		count = 0;
		j = 0;
		while(j < size)
		{
			if (value[i] > value[j])
				count++;
			j++;
		}
		mapping[i] = count + 1;
		i++;
	}
}

void    handle_error(t_data *data)
{
	free(data->stack_a.stack);
    free(data->stack_b.stack);
    write(2, "Error\n", 6);
    exit(1);
}

int get_nth_value(t_stack *stack, int n, bool from_top)
{
    int i;

    if (stack == NULL || n <= 0 || length(stack) < n)
        return -1;

	else if (from_top)
    	i = stack->top;
	else if (!from_top)
		i = stack->bottom;

    while (--n > 0)
	{
		if (from_top)
        	i = get_next_index(stack, i);
		else
			i = get_previous_index(stack, i);
	}
    return (stack->stack[i]);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

int	word_count(char *str)
{
	int		i = 0;
	int		wc = 0;

	if (str[i] == '\0')
    	return 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			i++;
		wc++;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
	}
	return (wc);
}

char	*get_word(char *str, int start, int end)
{
	int i = 0;
	char *word;

	word = malloc(sizeof(char)*(end - start + 2));
	if (!word)
		return (NULL);
	while (start <= end)
	{
		word[i] = str[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**arr;
	int		start;
	int 	end;
	int		i = 0;
	int		j = 0;
	int		wc = word_count(str);

	arr = malloc(sizeof(char *)*(wc + 1));
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		start = i;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			i++;
		end = i - 1;
		if (!arr)
			return (NULL);
		arr[j] = get_word(str, start, end);
		j++;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
	}
	return (arr);
}