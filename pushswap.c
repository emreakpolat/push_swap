/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:17:20 by makpolat          #+#    #+#             */
/*   Updated: 2025/01/27 13:37:58 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
static int *seperate(int argc, char *argv[])
{
    int i;
    int *k;
    int num;
    char **sprt;

    k =(int *)malloc(sizeof(argc));
    sprt = ft_split(argv[1], ' ');
    i = 0;
    while (sprt[i])
    {
        num = ft_atoi(sprt[i]);
        k[i] = num;
        i++;
    }
    k[i] = '\0';
    return k;
    
}
char *pushswap(int argc, char *argv[])
{
    int i;
    int *j;
    int k;

    k = 1;    
    i = 0;
    if (argc == 2)
    {
        j = seperate(argc, argv);
        while (j[i] != '\0') // Aynı elemandan iki tane var mı kontrolü
        {
            while (j[i] != j[k])
                i++;
            if (j[i] == j[k])
                return (write(1,"Error\n", 6));
            k++;
        }
        
        while (j[i] != '\0')
        {      
            ll_push(j[i]);
            i++;
        }
            
    }
    
    
}
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        return write(1,"Error",6);
    }
    pushswap(argc, argv);
}