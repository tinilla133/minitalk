/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:06:24 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/04/11 11:51:55 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#ifdef _LINUX_

int	ft_print_pointer(void *ptr, int *count)
{
	unsigned long long	nbr;
	int					error;

	if (ptr == NULL)
	{
		error = ft_putstr_couunt("(nil)", count);
		if (error == -1)
			return (-1);
	}
	else
	{
		nbr = (unsigned long long) ptr;
		error = ft_putstr_count("0x", count);
		if (error == -1)
			return (-1);
		error = ft_putnbr_base_count(nbr, HEX_LOWER, count);
		if (error == -1)
			return (-1);
	}
	return (*count);
}
#else

int	ft_print_pointer(void *ptr, int *count)
{
	unsigned long long	nbr;
	int					error;

	nbr = (unsigned long long) ptr;
	error = ft_putstr_count("0x", count);
	if (error < 0)
		return (-1);
	error = ft_putnbr_base_count(nbr, HEX_LOWER, count);
	if (error < 0)
		return (-1);
	return (*count);
}

#endif
