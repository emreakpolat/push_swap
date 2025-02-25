/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:21:21 by makpolat          #+#    #+#             */
/*   Updated: 2025/02/25 18:57:48 by makpolat         ###   ########.fr       */
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
void pb_low_index(t_general *stack)
{
    int     i;
    int     j;
    t_list *sort;

    i = listsize(stack->a);
    j = i;
    sort = stack->a;
    while (sort && j > 0)
    {
        if (sort->index <= (i / 2))
        {
            write(1, "pb\n", 3);
            ft_pb(stack);
            sort = stack->a;
        }
        else
        {
            write(1, "ra\n", 3);
            ft_ra(stack->a);
        }
        j--;
    }
}
void pb_all(t_general *stack)
{
    while (listsize(stack->a) > 3)
    {
        ft_pb(stack);
        write(1, "pb\n", 3);
    }
    
}

void bigsort(t_general *stack)
{
    indx(stack->a);
    pb_low_index(stack);
    //pb_all(stack);
    
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
