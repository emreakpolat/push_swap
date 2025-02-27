/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:21:21 by makpolat          #+#    #+#             */
/*   Updated: 2025/02/27 19:39:26 by makpolat         ###   ########.fr       */
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
        num = 2147483647;
        iter_a = a;
        while (iter_a)
        {
            if (iter_b->data < iter_a->data && num > iter_a->data)
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

t_list  *findcheapest(t_general *stack)
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
    return (cheapest);
}
static void	double_rev_rotate(t_general *a, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
        write(1, "rrr\n", 4);
		operator(a, "rrr");
	}
}
static void	double_rotate(t_general *stack, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_ra(stack->a);
        write(1, "ra\n", 3);
		ft_ra(stack->b);
        write(1, "rb\n", 3);

	}
}
static void	rotate_a(t_general *stack, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
            write(1, "ra\n", 4);
			ft_ra(stack->a);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
            write(1, "rra\n", 4);
			ft_rra(&stack->a);
			(*cost_b)++;
		}
	}
}

static void	rotate_b(t_general *stack, int *cost_a)
{
	while (*cost_a != 0)
	{
        if (*cost_a > 0)
        {
            write(1, "rb\n", 3);
            ft_ra(stack->b);
		    (*cost_a)--;
        }
        else if(*cost_a < 0)
        {
            write(1, "rr\n", 3);
		    operator(stack, "rr");
            (*cost_a)++;
        }
    }
}
void	move(t_general *stack, t_list *cheap)
{
    if (cheap->cost_a < 0 && cheap->cost_b < 0)
    {
        double_rev_rotate(stack, &cheap->cost_a, &cheap->cost_b);
    }
    else if (cheap->cost_a > 0 && cheap->cost_b > 0)
    {
        double_rotate(stack, &cheap->cost_a, &cheap->cost_b);
    }
    rotate_a(stack, &cheap->cost_a);
    rotate_b(stack, &cheap->cost_b);
	ft_pa(stack);
}

void bigsort(t_general *stack)
{
    t_list *cheap;
    indx(stack->a);
    pb_low_index(stack);
    pb_all(stack);
    position(stack);
    target_position(stack->b,stack->a);
    cost_function(stack);
    cheap = findcheapest(stack);
    while (stack->b)
    {
        cheap = findcheapest(stack);
        move(stack,cheap);
        position(stack);
        target_position(stack->b,stack->a);
        cost_function(stack); 
    }
    while (stack->a->index != 1)
    {
        ft_ra(stack->a);
    }
    
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
