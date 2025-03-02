/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:10:14 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/02 13:01:16 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sa(t_general *stack)
{
	int	temp;
	int	index;

	if (stack->a->next == NULL || stack->a == NULL)
		return ;
	index = stack->a->next->index;
	temp = stack->a->next->data;
	stack->a->next->data = stack->a->data;
	stack->a->data = temp;
	stack->a->next->index = stack->a->index;
	stack->a->index = index;
}

void	ft_sb(t_general *stack)
{
	int	temp;
	int	index;

	if (stack->b->next == NULL || stack->b == NULL)
		return ;
	index = stack->b->next->index;
	temp = stack->b->next->data;
	stack->b->next->data = stack->b->data;
	stack->b->data = temp;
	stack->b->next->index = stack->b->index;
	stack->b->index = index;
}

void	ft_pb(t_general *stack)
{
	t_list	*temp;

	if (stack->a == NULL)
		return ;
	write(1, "pb\n", 3);
	temp = stack->a;
	stack->a = stack->a->next;
	ft_lstadd_front(&stack->b, temp);
}

void	ft_pa(t_general *stack)
{
	t_list	*temp;

	if (!stack->b)
		return ;
	write(1, "pa\n", 3);
	temp = stack->b;
	stack->b = stack->b->next;
	ft_lstadd_front(&stack->a, temp);
}

void	ft_ra(t_list *stack)
{
	t_list	*iter;
	int		tmp;
	int		index;

	iter = stack;
	if (!stack)
		return ;
	tmp = iter->data;
	index = iter->index;
	while (iter->next)
	{
		iter->data = iter->next->data;
		iter->index = iter->next->index;
		iter = iter->next;
	}
	iter->data = tmp;
	iter->index = index;
}
