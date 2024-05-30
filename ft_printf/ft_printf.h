/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:52:52 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/04/04 10:36:42 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FD 1
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int				ft_printformat(va_list args, char format, int *count);
char			*ft_strchr(const char *s, int c);
unsigned int	ft_strlen(const char *s);
int				ft_putchar_count(char c, int *count);
int				ft_putstr_count(char *s, int *count);
int				ft_printf(char const *str, ...);
int				ft_putnbr_count(long int nbr, int *count);
int				ft_put_negative_count(long int *nbr, int *count);
int				ft_putulongnbr_count(unsigned long long nbr, int *count);
int				ft_putnbr_base_count(unsigned long long nbr, char *base, \
									int *count);
int				ft_print_pointer(void *ptr, int *count);

#endif
