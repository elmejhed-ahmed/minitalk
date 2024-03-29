/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejh <ael-mejh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:12:37 by ael-mejh          #+#    #+#             */
/*   Updated: 2024/03/29 14:41:48 by ael-mejh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

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
// int ft_bit(char *a)
// {}
int main(int ac , char **av)
{
    int pid;
	int i = 0;
	
    if (ac != 3)
        return (write(2, "Error\n", 6) ,1);
    pid = ft_atoi(av[1]);
   
		i = 0;
		while (av[2][i])
		{ 
			printf("%c", av[2][i]);
			i++;
		}
	
    // printf("%d",pid);
}