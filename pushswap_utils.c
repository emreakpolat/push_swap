/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:48:12 by makpolat          #+#    #+#             */
/*   Updated: 2025/02/22 22:39:51 by makpolat         ###   ########.fr       */
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
	
	if (!(*stack) || !(*stack)->next)
		return ;
	iter = *stack;
	tmp = *stack;
	while (iter->next)
		iter = iter->next;
	
	while (tmp->next != iter)
		tmp = tmp->next;
	
	tmp->next = NULL;
	iter->next = *stack;
	*stack = iter;
	// printf("stack %d\n", iter->data);
	// printf("stack %d\n", iter->next->data);
	// printf("stack %d\n", iter->next->next->data);
}

void	operator(t_general *stack, char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		ft_sa(stack);
	else if (ft_strcmp(str, "sb") == 0)
		ft_sa(stack);
	else if (ft_strcmp(str, "ss") == 0)
	{
		ft_sa(stack);
		ft_sa(stack);
	}
	else if (ft_strcmp(str, "pa") == 0)
		ft_pa(stack);
	else if (ft_strcmp(str, "pb") == 0)
		ft_pb(stack);
	else if (ft_strcmp(str, "ra") == 0)
		ft_ra(stack->a);
	else if (ft_strcmp(str, "rb") == 0)
		ft_ra(stack->b);
	else if (ft_strcmp(str, "rr") == 0)
	{
		ft_ra(stack->a);
		ft_ra(stack->b);
	}
	else if (ft_strcmp(str, "rra") == 0)
		ft_rra(&stack->a);
	else if (ft_strcmp(str, "rrb") == 0)
		ft_rra(&stack->b);
	else if (ft_strcmp(str, "rrr") == 0)
	{
		ft_rra(&stack->b);
		ft_rra(&stack->a);
	}
}
