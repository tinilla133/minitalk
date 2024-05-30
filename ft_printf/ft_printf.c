/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:27:13 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/04/11 12:46:57 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		count;
	int		error;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (ft_strchr("cspdiuxX%", *(str + 1)))
				error = ft_printformat(args, *(str + 1), &count);
			str++;
		}
		else
			error = ft_putchar_count(*str, &count);
		str++;
	}
	va_end(args);
	if (error < 0)
		return (-1);
	return (count);
}

int	ft_printformat(va_list args, char format, int *count)
{
	int	error;

	error = 0;
	if (format == 'c')
		error = ft_putchar_count(va_arg(args, int), count);
	else if (format == 's')
		error = ft_putstr_count(va_arg(args, char *), count);
	else if (format == 'd' || format == 'i')
		error = ft_putnbr_count(va_arg(args, int), count);
	else if (format == 'X')
		error = ft_putnbr_base_count(va_arg(args, unsigned int), \
				HEX_UPPER, count);
	else if (format == 'x')
		error = ft_putnbr_base_count(va_arg(args, unsigned int), \
				HEX_LOWER, count);
	else if (format == 'u')
		error = ft_putnbr_count((unsigned int) va_arg(args, unsigned int), \
			count);
	else if (format == '%')
		error = ft_putchar_count('%', count);
	else if (format == 'p')
		error = ft_print_pointer(va_arg(args, void *), count);
	if (error == -1)
		return (-1);
	return (*count);
}
