/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supanuso <supanuso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 21:46:37 by supanuso          #+#    #+#             */
/*   Updated: 2025/05/16 17:02:21 by supanuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_receiver = 0;

void	sig_handler(int signum)
{
	static int	i;
	char		buffer[12];
	int			n;
	int			len;

	g_receiver = 1;
	if (signum == SIGUSR1)
	{
		write(1, "Number of bytes received: ", 26);
		n = i / 8;
		len = 0;
		while (n > 0)
		{
			buffer[len] = '0' + (n % 10);
			n = n / 10;
			len++;
		}
		while (len > 0)
			write(1, &buffer[--len], 1);
		write(1, "\n", 1);
	}
	else if (signum == SIGUSR2)
		i++;
}

void	wait_ack(void)
{
	while (g_receiver == 0)
		;
	g_receiver = 0;
}

void	ft_char_to_bin(char c, int pid)
{
	int	bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		if ((c >> bit_index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		wait_ack();
		bit_index--;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;
	int					i;

	if (argc != 3)
	{
		write(1, "Usage: ./client <PID> <message>\n", 33);
		return (1);
	}
	pid = atoi(argv[1]);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	i = 0;
	while (argv[2][i])
	{
		ft_char_to_bin(argv[2][i], pid);
		i++;
	}
	ft_char_to_bin('\0', pid);
	return (0);
}
