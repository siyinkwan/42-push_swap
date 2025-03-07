/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguan <sguan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:40:47 by sguan             #+#    #+#             */
/*   Updated: 2024/12/03 16:32:08 by sguan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

void	ft_putstr(char *s);

int		ft_print_ptr(unsigned long int ptr);

int		ft_print_char(char c);

int		ft_print_str(char *s);

int		ft_print_nbr(int nbr);

int		ft_print_nbr_unsigned(unsigned int nbr, int print_count);

int		ft_print_hex(int nbr, char c);

int		ft_print_percent(void);

int		ft_check_format(va_list args, char specifier);

int		ft_printf(const char *str, ...);

#endif