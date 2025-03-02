/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:17:20 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/02 13:02:21 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void freelist(t_list *stack)
{
	t_list *temp;
	if (!stack)
		return;
	while (stack->next)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	free(stack);
}

int main(int argc, char *argv[])
{
	t_general *stack;

	control(argc, argv);
	stack = addlist(argc, argv);
	sorting(stack);

	freelist(stack->a);
	freelist(stack->b);
	free(stack);
}
