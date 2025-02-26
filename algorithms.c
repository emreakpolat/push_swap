/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:21:21 by makpolat          #+#    #+#             */
/*   Updated: 2025/02/26 05:08:07 by makpolat         ###   ########.fr       */
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
    threesort(stack);
}

void    position(t_general *stack)
{
    int     i;
    t_list  *temp;

    temp = stack->a;
    i = 0;
    while (temp)
    {
        temp->position = i;
        temp = temp->next;
        i++;
    }
    temp = stack->b;
    i = 0;
    while (temp)
    {
        temp->position = i;
        temp = temp->next;
        i++;
    }
}

void    target_position(t_list *b, t_list *a)
{
    int     num;
    t_list *iter_a;
    t_list *iter_b;

    iter_b = b;
    while (iter_b)
    {
        num = a->data;
        iter_a = a;
        while (iter_a)
        {
            if (num < iter_b->data)
            {
                num = iter_a->data;
                iter_b->target_pos = iter_a->position;
            }
            iter_a = iter_a->next;
        }
        iter_b = iter_b->next;
    }
}

void    cost_function(t_general *stack)
{
    t_list *temp_b;
    int     size_b;
    int     size_a;

    size_a = listsize(stack->a);
    size_b = listsize(stack->b);
    temp_b = stack->b;
    while (temp_b)
    {
        temp_b->cost_b = temp_b->position;
        temp_b->cost_a = temp_b->target_pos;
        if (temp_b->cost_b > (size_b / 2))
            temp_b->cost_b = (size_b - temp_b->position) * -1;
        if (temp_b->cost_a > (size_a / 2))
            temp_b->cost_a = (size_a - temp_b->target_pos) * -1;
        temp_b = temp_b->next;
    }
}

t_list    *findcheapest(t_general *stack)
{
    int     i;
    int     j;
    int     num;
    t_list  *cheapest;
    t_list  *iter;
    
    num = 2147483647;
    iter = stack->b;
    cheapest = iter;
    while (iter)
    {
        if (iter->cost_a < 0)
            i = (iter->cost_a * -1);
        if(iter->cost_b < 0)
            j = (iter->cost_b * -1);
        if ((i + j) < num)
        {
            num = (i + j);
            cheapest = iter;
        }
        iter = iter->next;
    }
    return  (cheapest);
}

static void     rev_rotate(t_general *stack, int *cost_a, int *cost_b)
{
    while(*cost_a < 0 && 0 > *cost_b)
    {
        ft_rra(stack->a);
        ft_rra(stack->b);
        *cost_a++;
        *cost_b++;
    }
}
static void     rotate(t_general *stack, int *cost_a, int *cost_b)
{
    while(*cost_a > 0 && 0 < *cost_b)
    {
        ft_ra(stack->a);
        ft_ra(stack->b);
        *cost_a++;
        *cost_b++;
    }
}
static void     doublerotate(t_list *stack, int *cost_a, int *cost_b)
{
    while (*cost_a)
	{
		if (*cost_a > 0)
		{
			ft_ra(stack);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			ft_rra(stack);
			(*cost_a)++;
		}
	}
}

void    push(t_general *stack, t_list *cheapest)
{
    int *cost_a;
    int *cost_b;

    cost_a = cheapest->cost_a;
    cost_b = cheapest->cost_b;
    if (cheapest->cost_a < 0 && 0 < cheapest->cost_b)
    {
        //rev_rotate(stack, &cheapest->cost_a, &cheapest->cost_b);
    }
    else if (cheapest->cost_a > 0 && 0 < cheapest->cost_b)
    {
        //rotate(stack, &cheapest->cost_a, &cheapest->cost_b);
    }
    //doublerotate(stack->a, &cheapest->cost_a, &cheapest->cost_b);
    //doublerotate(stack->b, &cheapest->cost_a, &cheapest->cost_b);
    ft_pa(stack);
}
void bigsort(t_general *stack)
{
    t_list *cheapest;

    indx(stack->a);
    pb_low_index(stack);
    pb_all(stack);
    position(stack);
    target_position(stack->b,stack->a);
    cost_function(stack);
    cheapest = findcheapest(stack->b);
    push(stack, cheapest);
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
