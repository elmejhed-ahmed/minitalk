/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejh <ael-mejh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:12:37 by ael-mejh          #+#    #+#             */
/*   Updated: 2024/06/22 15:32:53 by ael-mejh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					negat;
	int					count;
	unsigned long long	num;

	i = 0;
	negat = 1;
	count = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negat = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] == 48)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
		num = num * 10 + str[i++] - 48;
	return (negat * num);
}

void	ft_bit(unsigned char c, int pid)
{
	int	b;
	int	res;

	b = 7;
	res = 0;
	while (b >= 0)
	{
		res = c >> b & 1;
		if (res == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		usleep(300);
		b--;
	}
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
		return (write(2, "Error\n", 6), 1);
	while (av[1][i])
	{
		if (!ft_isdigit(av[1][i]))
			return (write(2, "Error\n", 6), 1);
		i++;
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0 && pid < 2147483647)
		return (write(2, "Error\n", 6), 1);
	i = 0;
	while (av[2][i])
	{
		ft_bit(av[2][i], pid);
		i++;
	}
	if (av[2][i] == '\0')
		ft_bit(av[2][i], pid);
	return (0);
}
