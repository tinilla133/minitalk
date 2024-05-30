/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:59:42 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/04/11 11:51:38 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_count(long int nbr, int *count)
{
	char	c;
	int		error;	

	error = ft_put_negative_count(&nbr, count);
	if (error < 0)
		return (-1);
	if (nbr >= 10)
	{
		error = ft_putnbr_count(nbr / 10, count);
		if (error == -1)
			return (-1);
		nbr = nbr % 10;
	}
	if (nbr < 10)
	{
		c = nbr + 48;
		error = write(FD, &c, 1);
		if (error < 0)
			return (-1);
	}
	*count += error;
	return (*count);
}

int	ft_put_negative_count(long int *nbr, int *count)
{
	int	error;

	if (*nbr < 0)
	{
		error = write(FD, "-", 1);
		if (error == -1)
			return (-1);
		*count += error;
		*nbr = -(*nbr);
	}
	return (*count);
}
