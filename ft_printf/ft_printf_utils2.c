/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:28:04 by sguan             #+#    #+#             */
/*   Updated: 2024/12/03 16:54:08 by sguan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr_unsigned(unsigned int nbr, int print_count)
{
	if (nbr > 9)
	{
		print_count = ft_print_nbr_unsigned(nbr / 10, print_count);
		print_count = ft_print_nbr_unsigned(nbr % 10, print_count);
	}
	else
	{
		ft_putchar_fd(nbr + '0', 1);
		print_count++;
	}
	return (print_count);
}

int	ft_print_hex(int nbr, char c)
{
	char			*hex_digits;
	char			hex_list[20];
	int				i;
	int				len;

	if (c == 'x')
		hex_digits = "0123456789abcdef";
	else if (c == 'X')
		hex_digits = "0123456789ABCDEFG";
	i = 0;
	if (nbr == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	while ((unsigned int)nbr > 0)
	{
		hex_list[i] = hex_digits[(unsigned int)nbr % 16];
		nbr = (unsigned int) nbr / 16;
		i++;
	}
	len = i;
	while (i > 0)
		ft_putchar_fd(hex_list[--i], 1);
	return (len);
}

int	ft_print_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
