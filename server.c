/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:49:50 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/05/27 21:12:08 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	action;

	ft_printf("PID: %d\n", getpid());
	action.sa_handler = sigusr_handler;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		(write(2, "Signal error.\n", 14), exit (-1));
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		(write(2, "signal error.\n", 14), exit (-1));
	while (1)
	{
		usleep(500);
	}
}

void	sigusr_handler(int sig)
{
	static unsigned char	byte;
	static unsigned int		bit_num;

	byte = byte << 1;
	if (sig == SIGUSR2)
		byte |= 1;
	bit_num++;
	if (bit_num == 8)
	{
		ft_printf("%c", byte);
		byte = 0;
		bit_num = 0;
	}
}
