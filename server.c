/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejh <ael-mejh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:36:24 by ael-mejh          #+#    #+#             */
/*   Updated: 2024/04/01 23:33:17 by ael-mejh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void ft_handler(int sig, siginfo_t *info, void *context) 
{
    static char bit;
    static int i = 7;
    static int old_pid;

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
        write(1, &bit, 1);
        i = 8;
        bit = 0;
    }
    i--;
}
static ft_putnbr(int nb, int fd)
{
    
}

int main(int ac, char **av)
{
    struct  sigaction sig;
    sig.sa_sigaction = ft_handler;
    sig.sa_flags = SA_SIGINFO;

    if (ac != 1)
        return (write(2, "Error\n", 6), 1);
    printf("PID: %d\n", getpid());
    
    if (sigaction(SIGUSR1, &sig, NULL) == -1)
        return 1;
    if (sigaction(SIGUSR2, &sig, NULL) == -1)
        return 1;
    while (1)
        pause();
    return (0);
}
