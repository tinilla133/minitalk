/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:10:10 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/04/04 19:22:40 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	char			*ptrs;

	ptrs = (char *) s;
	while (*ptrs)
	{
		if (*ptrs == (char) c)
			return (ptrs);
		ptrs++;
	}
	if (*ptrs == (char) c)
		return (ptrs);
	return (NULL);
}

unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
