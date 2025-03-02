/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:21:21 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/02 15:54:37 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	listsize(t_list *list)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = list;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

static t_list	*less_node(t_list *stack)
{
	t_list	*temp;
	t_list	*iter;
	int		i;

	iter = stack;
	temp = NULL;
	i = 0;
	if (iter)
	{
		while (iter)
		{
			if (iter->index == -1 && (!i || iter->data < temp->data))
			{
				temp = iter;
				i = 1;
			}
			iter = iter->next;
		}
	}
	return (temp);
}

static void	indx(t_list *stack)
{
	t_list	*iter;
	int		index;

	index = 0;
	iter = less_node(stack);
	while (iter)
	{
		iter->index = index++;
		iter = less_node(stack);
	}
}

int	maximum_bits(t_list *stack)
{
	t_list	*iter;
	int		maximum;
	int		find_bits;

	iter = stack;
	maximum = iter->index;
	find_bits = 0;
	while (iter)
	{
		if (iter->index > maximum)
			maximum = iter->index;
		iter = iter->next;
	}
	while ((maximum >> find_bits) != 0)
		find_bits++;
	return (find_bits);
}

void	sorting(t_general *stack)
{
	int	i;

	i = listsize(stack->a);
	indx(stack->a);
	if (i < 2)
		return ;
	if (is_sort(stack->a))
		return ;
	if (i == 2)
	{
		ft_sa(stack);
		write(1, "sa\n", 3);
	}
	else if (i == 3)
		threesort(stack);
	else if (i == 4)
		foursort(stack);
	else if (i == 5)
		fivesort(stack);
	else
		bigsort(stack, 0, 0, listsize(stack->a));
}
