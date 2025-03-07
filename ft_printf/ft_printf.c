/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:42:44 by sguan             #+#    #+#             */
/*   Updated: 2024/12/03 16:30:59 by sguan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(va_list args, char specifier)
{
	char	*str_arg;

	if (specifier == 'c')
		return (ft_print_char((char)va_arg(args, int)));
	else if (specifier == 's')
	{
		str_arg = va_arg(args, char *);
		if (str_arg == NULL)
			return (ft_print_str("(null)"));
		return (ft_print_str(str_arg));
	}
	else if (specifier == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long int)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_print_nbr_unsigned(va_arg(args, unsigned int), 0));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_print_hex(va_arg(args, int), specifier));
	else if (specifier == '%')
		return (ft_print_percent());
	ft_putchar_fd('%', 1);
	ft_putchar_fd(specifier, 1);
	return (2);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		print_count;

	print_count = 0;
	if (!str)
		return (0);
	va_start(args, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			print_count += ft_check_format(args, str[i + 1]);
			i++;
		}
		else
			print_count += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (print_count);
}
