/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:03:57 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/04/11 11:51:10 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_count(unsigned long long nbr, char *base, int *count)
{
	char				c;
	unsigned int		base_dim;
	int					error;

	base_dim = ft_strlen(base);
	if (base_dim < 2)
		return (0);
	if (nbr < base_dim)
	{
		c = base[nbr % base_dim];
		error = write(FD, &c, 1);
		if (error < 0)
			return (-1);
		*count += error;
	}
	else
	{
		ft_putnbr_base_count(nbr / base_dim, base, count);
		c = base[nbr % base_dim];
		error = write(FD, &c, 1);
		if (error < 0)
			return (-1);
		*count += error;
	}
	return (*count);
}
