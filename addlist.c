/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:55:15 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/02 15:57:22 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_lstadd_back(t_general *stack, t_list *new)
{
	if (!new || !stack)
		return ;
	if (stack == NULL)
	{
		stack->a = new;
		new->next = NULL;
	}
	else
		ft_lstlast(stack->a)->next = new;
}

t_list	*ft_lstnew(t_general *stack, int data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->index = -1;
	if (stack->a == NULL)
	{
		stack->a = node;
	}
	else
	{
		ft_lstadd_back(stack, node);
	}
	node->next = NULL;
	return (stack->a);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_front(t_list **stack, t_list *new)
{
	if (!new)
		return ;
	new->next = *stack;
	*stack = new;
}
