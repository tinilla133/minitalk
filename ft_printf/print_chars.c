/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:49:47 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/04/11 11:54:32 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_printf.h"

int	ft_putchar_count(char c, int *count)
{
	int	error;

	error = write(FD, &c, 1);
	if (error < 0)
		return (-1);
	*count += error;
	return (*count);
}

int	ft_putstr_count(char *s, int *count)
{
	int	error;

	if (s == NULL)
	{
		error = write(FD, "(null)", 6);
		if (error < 0)
			return (-1);
		*count += error;
		return (*count);
	}
	while (*s)
		ft_putchar_count(*(s++), count);
	return (*count);
}
