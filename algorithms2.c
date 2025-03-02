/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:02:45 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/02 10:56:51 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */






// t_list	*get_min(t_list *stack)
// {
// 	t_list	*min;
// 	t_list	*node;
// 	int		control;

// 	node = stack;
// 	min = NULL;
// 	control = 0;
// 	if (node)
// 	{
// 		while (node)
// 		{
// 			if (node->index == -1 && (!control || node->data < min->data))
// 			{
// 				min = node;
// 				control = 1;
// 			}
// 			node = node->next;
// 		}
// 	}
// 	return (min);
// }

// void	add_index(t_list *stack)
// {
// 	t_list	*node;
// 	int		index;

// 	index = 0;
// 	node = get_min(stack);
// 	while (node)
// 	{
// 		node->index = index++;
// 		node = get_min(stack);
// 	}
// }


// int	is_sorted(t_list *stack)
// {
// 	t_list	*node;

// 	node = stack;
// 	if (!node || !node->next)
// 		return (1);
// 	while (node->next)
// 	{
// 		if (node->data > node->next->data)
// 			return (0);
// 		node = node->next;
// 	}
// 	return (1);
// }


// t_list	*min_node(t_list *stack)
// {
// 	t_list	*tmp;
// 	t_list	*min;

// 	if (!stack || !stack)
// 		return (NULL);
// 	min = stack;
// 	tmp = min->next;
// 	while (tmp != NULL)
// 	{
// 		if (tmp->index < min->index)
// 			min = tmp;
// 		tmp = tmp->next;
// 	}
// 	return (min);
// }


// void	position(t_general *stack)
// {
// 	t_list	*node;

// 	node = stack->a;
// 	if (min_node(stack->a) == ft_lstlast(stack->a))
// 		ft_rra(&stack->a);
// 	else
// 	{
// 		while (min_node(stack->a) != node)
// 		{
// 			ft_ra(stack->a);
//             write(1, "ra\n", 3);

// 			node = stack->a;
// 		}
// 	}
// 	ft_pb(stack);
//     write(1, "pb\n", 3);

// }

// int	get_max_bits(t_list *stack)
// {
// 	t_list	*head;
// 	int		max;
// 	int		max_bits;


// 	head = stack;
// 	max = head->index;
// 	max_bits = 0;
// 	while (head)
// 	{
// 		if (head->index > max)
// 			max = head->index;
// 		head = head->next;
// 	}
// 	while ((max >> max_bits) != 0)
// 		max_bits++;
// 	return (max_bits);
// }

// void threesort(t_general *stack)
// {
//     t_list *temp;

//     temp = stack->a;

//     if (temp->data > temp->next->data)
//     {
//         write(1, "sa\n", 3);
//         ft_sa(stack);
//     }
//     temp = stack->a;
//     if (temp->next->data > temp->next->next->data)
//     {
//         write(1, "rra\n", 4);
//         ft_rra(&stack->a);
//     }
//     temp = stack->a;
//     if (temp->next->data < temp->data)
//     {
//         write(1, "sa\n", 3);
//         ft_sa(stack);
//     }
// }

// void	sort_4(t_general *stack)
// {
// 	if (is_sorted(stack->a))
// 		return ;
// 	position(stack);
// 	threesort(stack);
// 	ft_pa(stack);
//     write(1, "pa\n", 3);

// }

// void	sort_5(t_general *stack)
// {
// 	position(stack);
// 	sort_4(stack);
// 	ft_pa(stack);
//     write(1, "pa\n", 3);
// }

// void	radix(t_general *stack)
// {
// 	int		size;
// 	int		max_bits;
// 	int		i;
// 	int		j;
// 	t_list	*node;

// 	size = listsize(stack->a);
// 	max_bits = get_max_bits(stack->a);
// 	i = 0;
// 	while (i < max_bits)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			node = stack->a;
// 			if (((node->index >> i) & 1) == 1)
//             {
// 				ft_ra(stack->a);
//                 write(1, "ra\n", 3);

//             }
// 			else
//             {
// 				ft_pb(stack);
//                 write(1, "pb\n", 3);

//             }
//             j++;
// 		}
// 		while (stack->b)
//         {
// 			ft_pa(stack);
//             write(1, "pa\n", 3);
//         }
//         i++;
// 	}
// }



// void sorting(t_general *stack)
// {
// add_index(stack->a);
// 	if (listsize(stack->a) < 2)
// 		return ;
// 	if (is_sorted(stack->a))
// 		return ;
// 	if (listsize(stack->a) == 2)
//     {
//         ft_sa(stack);
//         write(1, "sa\n", 3);
//     }
// 	else if (listsize(stack->a) == 3)
// 		threesort(stack);
// 	else if (listsize(stack->a) == 4)
// 		sort_4(stack);
// 	else if (listsize(stack->a) == 5)
// 		sort_5(stack);
// 	else
// 		radix(stack);
// }
