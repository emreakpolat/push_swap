/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:17:20 by makpolat          #+#    #+#             */
/*   Updated: 2025/02/13 17:12:28 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


int main(int argc, char *argv[])
{
	control(argc, argv);
	t_general *stack = addlist(argc, argv);
	printf("burada\n");
	while (stack->a)
	{
		printf("%d\n",stack->a->data);
		stack->a = stack->a->next;
	}
	
}
