/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:02:45 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/02 12:57:56 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	threesort(t_general *stack)
{
	t_list	*temp;

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

void	foursort(t_general *stack)
{
	if (is_sort(stack->a))
		return ;
	position(stack);
	threesort(stack);
	ft_pa(stack);
	write(1, "pa\n", 3);
}

void	fivesort(t_general *stack)
{
	position(stack);
	foursort(stack);
	ft_pa(stack);
	write(1, "pa\n", 3);
}

void	bigsort(t_general *stack, int i, int j, int stack_size)
{
	t_list	*node;
	int		max;

	max = maximum_bits(stack->a);
	while (i < max)
	{
		j = 0;
		while (j < stack_size)
		{
			node = stack->a;
			if (((node->index >> i) & 1) == 1)
			{
				ft_ra(stack->a);
				write(1, "ra\n", 3);
			}
			else
				ft_pb(stack);
			j++;
		}
		while (stack->b)
			ft_pa(stack);
		i++;
	}
}
