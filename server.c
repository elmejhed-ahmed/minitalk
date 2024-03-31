/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mejh <ael-mejh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:36:24 by ael-mejh          #+#    #+#             */
/*   Updated: 2024/03/31 22:00:14 by ael-mejh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void ft_handler(int sig, )
{
    static char buffer[8];
    static int i;
    i++;
  
    
}
int main(int ac, char **av)
{
    struct sigaction sig;
    sig.sa_handler = ft_handler;
    sig.sa_flags = 0;
    pid_t pid;
    
    pid = getpid();
    printf("%d", pid);
    if(ac > 1)
        return (write(2, "Error\n", 6),1);
    
    sigaction(SIGUSR1,&sig,NULL);
    sigaction(SIGUSR2,&sig,NULL);
    


    return 0;
}
