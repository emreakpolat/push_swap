/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:21:21 by makpolat          #+#    #+#             */
/*   Updated: 2025/02/22 23:25:10 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int countlist(t_list *list)
{
    int i;
    t_list *temp;

    i = 0;
    temp = list;
    while (temp)
    {
        i++;
        temp = temp->next;
    }
    return (i);
}


void  twosort(t_general *stack)
{
    if (stack->a->next->data < stack->a->data)
    {
        ft_ra(stack->a);
        write(1, "ra\n", 3);
    }
}

void threesort(t_general *stack)
{
    t_list *temp;

    temp = stack->a;

    if (temp->data > temp->next->data)
    {
        write(1, "sa\n", 3);
        ft_sa(stack);
    }
    temp = stack->a;
    if (temp->next->data > temp->next->next->data)
    {
        write(1, "rra\n", 4);
        ft_rra(&stack->a);
    }
    temp = stack->a;
    if (temp->next->data < temp->data)
    {
        write(1, "sa\n", 3);
        ft_sa(stack);
    }
}

// void index(t_list *a)
// {
//     int     num;
//     int     i;
//     t_list  *iter;

//     i = 1;
//     iter = a;
//     num = iter->data;
//     while (iter)
//     {
//         if (num > iter->data)
//         {
//             num = iter->data;
//             iter->index = i;
//         }
//         iter = iter->next;
//     }
    
//     iter = a;
//     while (iter)
//     {
//         if (iter->index == 1)
//         {
//             iter =
//         }
//     }
    
    
// }

// void bigsort(t_general *stack)
// {
//     index(stack->a);
// }


// void sorting(t_general *stack)
// {
//     int i;
//     i = countlist(stack->a);
//     if (i == 2)
//         twosort(stack);
//     else if (i == 3)
//         threesort(stack);
//     else
//         bigsort(stack);
// }
