/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejh <ael-mejh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:36:24 by ael-mejh          #+#    #+#             */
/*   Updated: 2024/04/01 01:15:01 by ael-mejh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void ft_handler(int sig, siginfo_t *info, void *context) 
{
    // static char buffer;
    // static int i;
    printf("signal %d ///// PID : %d", sig, info->si_pid);
    
    // int res;
    // res = 0;
    // if (sig == SIGUSR1)
    // {
    //     printf("dddd");
    //     //res = (0 << i & 1);
    //     buffer = res;
    // }
        
    // if (i == 8)
    // {
    //     printf("%c", buffer);

    //     i = 0;
    // }
    // i++;
}

int main(int ac, char **av)
{
    struct  sigaction sig;
    sig.sa_sigaction = ft_handler;
    sig.sa_flags = SA_SIGINFO;

    if(ac > 1)
        return (write(2, "Error\n", 6), 1);
    
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
        sleep(1);
    }
    https://www.phind.com/search?cache=u9awpp48dwbz9e9z6mdd3dca
    // return 0;
}



