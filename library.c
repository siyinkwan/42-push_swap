/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:25:06 by sguan             #+#    #+#             */
/*   Updated: 2025/03/07 12:25:34 by sguan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	if (str[i] == '\0')
		return (0);
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
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (end - start + 2));
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
	int		i;
	int		j;
	int		wc;

	i = 0;
	j = 0;
	wc = word_count(str);
	arr = malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		start = i;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			i++;
		arr[j] = get_word(str, start, i - 1);
		j++;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
	}
	return (arr);
}
