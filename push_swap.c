/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:17:20 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/02 10:14:52 by makpolat         ###   ########.fr       */
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

void print(t_list *list)
{
	t_list *temp;
	temp = list;
	int i = 0;
	while (temp)
	{
		printf("değer: %d   ", temp->data);
		printf("index: %d\n", temp->index);
		i++;
		temp = temp->next;
	}
}

int main(int argc, char *argv[])
{
	t_general *stack;

	control(argc, argv);
	stack = addlist(argc, argv);
	sorting(stack);

	// printf("A\n");
	// print(stack->a);

	// printf("------\n");
	// printf("B\n");
	// print(stack->b);

	freelist(stack->a);
	freelist(stack->b);
	free(stack);
}
