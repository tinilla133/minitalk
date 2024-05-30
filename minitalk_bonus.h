/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:54:58 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/05/28 14:21:34 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

typedef struct s_byte
{
	unsigned int	bit_num;
	unsigned char	byte;
}				t_byte;

int		ft_atoi(const char *str);
int		ft_send_byte(unsigned char byte, int pid);
void	sigusr_handler(int sig, siginfo_t *info, void *ucontext);
void	sig_handler_client(int sig);

#endif