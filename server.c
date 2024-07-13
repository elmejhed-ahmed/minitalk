/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejh <ael-mejh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:36:24 by ael-mejh          #+#    #+#             */
/*   Updated: 2024/06/22 15:45:51 by ael-mejh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	n;

	n = nb;
	if (fd > 0)
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			nb *= (-1);
		}
		if (nb > 9)
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putnbr_fd(nb % 10, fd);
		}
		if (nb >= 0 && nb <= 9)
		{
			nb += 48;
			write(fd, &nb, 1);
		}
	}
}

void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static char	bit;
	static int	i;
	static int	old_pid;

	i = 7;
	(void)context;
	if (old_pid == 0)
		old_pid = info->si_pid;
	else if (info->si_pid != old_pid)
	{
		old_pid = info->si_pid;
		i = 7;
		bit = 0;
	}
	if (sig == SIGUSR2)
		bit |= (1 << i);
	if (i == 0)
	{
		if (bit == '\0')
			write(1, "\n", 1);
		else
			write(1, &bit, 1);
		i = 8;
		bit = 0;
	}
	i--;
}

int	main(int ac, char **av)
{
	struct sigaction	sig;

	sig.sa_sigaction = ft_handler;
	sig.sa_flags = SA_SIGINFO;
	(void)av;
	if (ac != 1)
		return (write(2, "Error\n", 6), 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	if (sigaction(SIGUSR1, &sig, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sig, NULL) == -1)
		return (1);
	while (1)
		pause();
	return (0);
}
