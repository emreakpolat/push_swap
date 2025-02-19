/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:17:20 by makpolat          #+#    #+#             */
/*   Updated: 2025/02/19 18:26:41 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
void print(t_list *list)
{
	t_list *temp;
	temp=list;
	while (temp)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}

int main(int argc, char *argv[])
{
	control(argc, argv);
	t_general *stack = addlist(argc, argv);
	// t_list *root_a = stack->a;
	// t_list *root_b = stack->b;

	operator(stack, "rra");
	printf("A\n");
	
	print(stack->a);

	printf("------\n");
	printf("B\n");
	print(stack->b);
	
}

