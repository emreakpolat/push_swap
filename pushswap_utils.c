/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:48:12 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/02 13:53:33 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	tekrarcheck(int *ptr, int len, char *seperate[])
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < len)
	{
		k = i + 1;
		while (k < len)
		{
			if (ptr[k] == ptr[i])
			{
				free(ptr);
				free_all(seperate);
				error("Error\n");
			}
			k++;
		}
		i++;
	}
}

void	sayicheck(char *seperate[])
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (seperate[i])
	{
		k = 0;
		while (seperate[i][k])
		{
			if (ft_isdigit(seperate[i][k]) == 0)
			{
				free_all(seperate);
				error("Error\n");
			}
			k++;
		}
		i++;
	}
}

t_general	*addlist(int argc, char **argv)
{
	int			i;
	char		**seperate;
	t_general	*stack;

	stack = malloc(sizeof(t_general));
	stack->a = NULL;
	stack->b = NULL;
	i = 0;
	if (argc == 2)
	{
		seperate = ft_split(argv[1], ' ');
		while (seperate[i])
		{
			stack->a = ft_lstnew(stack, ft_atoilst(seperate[i]));
			i++;
		}
		free_all(seperate);
	}
	else
	{
		while (argv[++i])
			stack->a = ft_lstnew(stack, ft_atoilst(argv[i]));
	}
	return (stack);
}

void	ft_rra(t_list **stack)
{
	t_list	*iter;
	t_list	*tmp;
	int		index;

	if (!(*stack) || !(*stack)->next)
		return ;
	iter = *stack;
	tmp = *stack;
	index = tmp->index;
	while (iter->next)
		iter = iter->next;
	while (tmp->next != iter)
		tmp = tmp->next;
	tmp->next = NULL;
	iter->next = *stack;
	iter->next->index = index;
	*stack = iter;
}
