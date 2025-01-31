/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:17:20 by makpolat          #+#    #+#             */
/*   Updated: 2025/01/31 18:55:57 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int repeatcheck(int *ptr)
{
    int i;
    int k;

    i = 0;
    while (ptr[i])
    {
        k = i + 1;
        while (ptr[k])
        {
            if (ptr[i] == ptr[k])    // Aynı sayıdan başka var mı kontrolü
                return (1);
            k++;
        }
        i++;
    }
    return 0;
}

int *sayidonustur(int argc, char *argv[])
{
    int *ptr;
    int i;

    ptr =(int *)malloc(sizeof(int) * argc);
    i = 0;
    argc = 0;
    while (argv[++i])
    {
        while (argv[i][argc])
        {
            if (ft_isdigit(argv[i][argc]) == 0) // bu bir sayı mı değil mi kontrolü
            {
                free(ptr);
                return (NULL);
            }
            argc++;
        }
        argc = 0;
        ptr[i - 1] = ft_atoi(argv[i], ptr); //sayıya dönüştürme işlemi
    }
    if (repeatcheck(ptr) == 1) // aynı sayıdan başka var mı fonksiyonu
        return (NULL);
    return (ptr);
}

char *pushswap(int argc, char *argv[])
{
    int i;
    int *ptr;

    ptr = sayidonustur(argc, argv);
    if (ptr == NULL)
        return ("Aynı sayı tekrar edemez\n");
    i = 0;
    while (ptr[i])
    {
        printf(" %d \n", ptr[i]);                                  
        i++;
    }
   return (char *)ptr;

}
int main(int argc, char *argv[])
{
    printf("%s",pushswap(argc, argv));
}