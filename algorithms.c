/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:21:21 by makpolat          #+#    #+#             */
/*   Updated: 2025/02/23 04:37:27 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int listsize(t_list *list)
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

void indx(t_list *a)
{
    int     i;
    t_list  *iter;
    t_list *tmp;

    iter = a;
    i = listsize(a);
	while (i > 0)
	{
        iter = a;
        tmp = NULL;
		while (iter)
		{
			if (iter->index == 0 && (tmp == NULL || iter->data > tmp->data))
				tmp = iter;
			iter = iter->next;
		}
		if (tmp)
			tmp->index = i;
		i--;
	}
}
void pbfunction(t_general *stack)
{
    int     i;
    t_list *iter;
    iter = stack->a;
    i = listsize(iter);
    while (iter)
    {
        if (iter->index <= (i / 2))
        {
            ft_pb(stack);
        }
        else
        {
            ft_ra(stack->a);
        }
        iter = iter->next;
    }
    
}

void bigsort(t_general *stack)
{
    indx(stack->a);
    pbfunction(stack);
    
}


void sorting(t_general *stack)
{
    int i;
    i = listsize(stack->a);
    if (i == 2)
        twosort(stack);
    else if (i == 3)
        threesort(stack);
    else
        bigsort(stack);
}
