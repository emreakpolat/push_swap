/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:47:45 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/02 15:58:49 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_list	*min_node(t_list *stack)
{
	t_list	*iter;
	t_list	*min;

	if (!stack)
		return (NULL);
	min = stack;
	iter = min->next;
	while (iter != NULL)
	{
		if (iter->index < min->index)
			min = iter;
		iter = iter->next;
	}
	return (min);
}

int	is_sort(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	if (!temp || !temp->next)
		return (1);
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	position(t_general *stack)
{
	t_list	*node;

	node = stack->a;
	if (min_node(stack->a) == ft_lstlast(stack->a))
	{
		ft_rra(&stack->a);
		write(1, "rra\n", 4);
	}
	else
	{
		while (min_node(stack->a) != node)
		{
			ft_ra(stack->a);
			write(1, "ra\n", 3);
			node = stack->a;
		}
	}
	ft_pb(stack);
	write(1, "pb\n", 3);
}
