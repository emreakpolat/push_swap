/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hamleler.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:10:14 by makpolat          #+#    #+#             */
/*   Updated: 2025/02/22 23:54:11 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sa(t_general *stack)
{
	int	temp;

	if (stack->a->next == NULL || stack->a == NULL)
		return ;
	temp = stack->a->next->data;
	stack->a->next->data = stack->a->data;
	stack->a->data = temp;
}

void	ft_sb(t_general *stack)
{
	int	temp;

	if (stack->b->next == NULL || stack->b == NULL)
		return ;
	temp = stack->b->next->data;
	stack->b->next->data = stack->b->data;
	stack->b->data = temp;
}

void	ft_pb(t_general *stack)
{
	t_list	*temp;

	if (stack->a == NULL)
		return ;
	temp = stack->a;
	stack->a = stack->a->next;
	ft_lstadd_front(&stack->b, temp);
}

void	ft_pa(t_general *stack)
{
	t_list	*temp;

	if (!stack->b)
		return ;
	temp = stack->b;
	ft_lstadd_front(&stack->a, temp);
	stack->b = stack->b->next;
	free(temp);
}

void	ft_ra(t_list *stack)
{
	t_list	*iter;
	int		tmp;

	iter = stack;
	if (!stack)
		return ;
	tmp = iter->data;
	while (iter->next)
	{
		iter->data = iter->next->data;
		iter = iter->next;
	}
	iter->data = tmp;
}
