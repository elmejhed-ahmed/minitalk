/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejh <ael-mejh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:36:24 by ael-mejh          #+#    #+#             */
/*   Updated: 2024/04/01 17:14:37 by ael-mejh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void ft_handler(int sig, siginfo_t *info, void *context) 
{
    static char bit;
    static int i;

    i++;
    if (sig == SIGUSR1)
        printf("user1-->%d\n",  bit|= (0 << i));
    if (sig == SIGUSR2)
        printf("user2-->%d\n", bit |= (1 << i));
    
    if (i == 8)
    {
        printf("%d\n", bit);
        i = 0;
        bit = 0;
    }

}

int main(int ac, char **av)
{
    struct  sigaction sig;
    sig.sa_sigaction = ft_handler;
    sig.sa_flags = SA_SIGINFO;

    if (ac > 1) {
        write(2, "Error\n", 6);
        return 1;
    }
    
    printf("PID: %d\n", getpid());
    
    if (sigaction(SIGUSR1, &sig, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    if (sigaction(SIGUSR2, &sig, NULL) == -1) {
        perror("sigaction");
        return 1;
    }
    
    while (1) {
        pause();
    }
    
    return 0;
}



