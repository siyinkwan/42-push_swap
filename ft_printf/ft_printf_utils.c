/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:41:08 by sguan             #+#    #+#             */
/*   Updated: 2024/12/03 14:55:07 by sguan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_print_ptr(unsigned long int ptr)
{
	char	*hex_digits;
	char	hex_str[20];
	int		i;
	int		remainder;
	int		len;

	hex_digits = "0123456789abcdef";
	i = 0;
	if (ptr == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	while (ptr > 0)
	{
		remainder = ptr % 16;
		hex_str[i] = hex_digits[remainder];
		ptr = ptr / 16;
		i++;
	}
	len = i;
	ft_putstr("0x");
	while (i-- > 0)
		write(1, &hex_str[i], 1);
	return (2 + len);
}

int	ft_print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_str(char *s)
{
	int	len;

	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	return (len);
}

int	ft_print_nbr(int nbr)
{
	char	*str;
	int		len;

	ft_putnbr_fd(nbr, 1);
	str = ft_itoa(nbr);
	len = ft_strlen(str);
	free(str);
	return (len);
}
