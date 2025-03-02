// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   algorithms.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/02/22 18:21:21 by makpolat          #+#    #+#             */
// /*   Updated: 2025/03/02 08:47:16 by makpolat         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

 #include "pushswap.h"

int listsize(t_list *list)
{
    int i;
    t_list *temp;

    i = 0;
    temp = list;
    while (temp)
    {
        i++;
        temp = temp->next;
    }
    return (i);
}


// void  twosort(t_general *stack)
// {
//     if (stack->a->next->data < stack->a->data)
//     {
//         ft_ra(stack->a);
//         write(1, "ra\n", 3);
//     }
// }



// void    position(t_general *stack)
// {
//     int     i;
//     t_list  *temp;

//     temp = stack->a;
//     i = 0;
//     while (temp)
//     {
//         temp->position = i;
//         temp = temp->next;
//         i++;
//     }
//     temp = stack->b;
//     i = 0;
//     while (temp)
//     {
//         temp->position = i;
//         temp = temp->next;
//         i++;
//     }
// }
// #include <limits.h>
// void    target_position(t_list *b, t_list *a)
// {
//     int     num;
//     t_list *iter_a;
//     t_list *iter_b;

//     iter_b = b;
//     while (iter_b)
//     {
//         num = INT_MAX;
//         iter_a = a;
//         while (iter_a)
//         {
//             if (iter_b->data < iter_a->data && num > iter_a->data)
//             {
//                 num = iter_a->data;
//                 iter_b->target_pos = iter_a->position;
//             }
//             iter_a = iter_a->next;
//         }
//         if (num == INT_MAX)
//         {
//             iter_a = a;
//             num = iter_a->data;
//             iter_b->target_pos = iter_a->position;
//             while (iter_a)
//             {
//                 if (iter_a->data < num)
//                 {
//                     num = iter_a->data;
//                     iter_b->target_pos = iter_a->position;
//                 }
//                 iter_a = iter_a->next;
//             }
//         }
//         iter_b = iter_b->next;
//     }
// }

// void    cost_function(t_general *stack)
// {
//     t_list *temp_b;
//     int     size_b;
//     int     size_a;

//     size_a = listsize(stack->a);
//     size_b = listsize(stack->b);
//     temp_b = stack->b;
//     while (temp_b)
//     {
//         temp_b->cost_b = temp_b->position;
//         temp_b->cost_a = temp_b->target_pos;
//         if (temp_b->position > (size_b / 2))
//             temp_b->cost_b = (size_b - temp_b->position) * -1;
//         if (temp_b->target_pos > (size_a / 2))
//             temp_b->cost_a = (size_a - temp_b->target_pos) * -1;
//         temp_b = temp_b->next;
//     }
// }

// static void	double_rev_rotate(t_general *a, int *cost_a, int *cost_b)
// {
// 	while (*cost_a < 0 && *cost_b < 0)
// 	{
// 		(*cost_a)++;
// 		(*cost_b)++;
//         write(1, "rrr\n", 4);
// 		operator(a, "rrr");
// 	}
// }
// static void	double_rotate(t_general *stack, int *cost_a, int *cost_b)
// {
// 	while (*cost_a > 0 && *cost_b > 0)
// 	{
// 		(*cost_a)--;
// 		(*cost_b)--;
// 		ft_ra(stack->a);
// 		ft_ra(stack->b);
//         write(1, "rr\n", 3);
// 	}
// }
// static void	rotate_a(t_general *stack, int *cost_b)
// {
// 	while (*cost_b)
// 	{
// 		if (*cost_b > 0)
// 		{
//             write(1, "ra\n", 3);
// 			ft_ra(stack->a);
// 			(*cost_b)--;
// 		}
// 		else if (*cost_b < 0)
// 		{
//             write(1, "rra\n", 4);
// 			ft_rra(&stack->a);
// 			(*cost_b)++;
// 		}
// 	}
// }

// static void	rotate_b(t_general *stack, int *cost_a)
// {
// 	while (*cost_a)
// 	{
//         if (*cost_a > 0)
//         {
//             write(1, "rb\n", 3);
//             ft_ra(stack->b);
// 		    (*cost_a)--;
//         }
//         else if(*cost_a < 0)
//         {
//             write(1, "rrb\n", 4);
// 		    operator(stack, "rrb");
//             (*cost_a)++;
//         }
//     }
// }




// void	move(t_general *stack, t_list *cheap)
// {
//     if (cheap->cost_a < 0 && cheap->cost_b < 0)
//     {
//         double_rev_rotate(stack, &cheap->cost_a, &cheap->cost_b);
//     }
//     else if (cheap->cost_a > 0 && cheap->cost_b > 0)
//     {
//         double_rotate(stack, &cheap->cost_a, &cheap->cost_b);
//     }

//     rotate_a(stack, &cheap->cost_a);
//     rotate_b(stack, &cheap->cost_b);

    

// }

// void  findcheapest(t_general *stack)
// {
//     int     i;
//     int     j;
//     int     num;
//     t_list  *cheapest;
//     t_list  *iter;
    
//     num = 2147483647;
//     iter = stack->b;
//     cheapest = iter;
//     while (iter)
//     {
//         if (iter->cost_a < 0)
//             i = (iter->cost_a * -1);
//         if(iter->cost_b < 0)
//             j = (iter->cost_b * -1);
//         if ((i + j) < num)
//         {
//             num = (i + j);
//             cheapest = iter;
//         }
//         iter = iter->next;
//     }
//     move(stack,cheapest);
// }
// void pb_all(t_general *stack)
// {
//     while (listsize(stack->a) > 3)
//     {
//         ft_pb(stack);
//         write(1 ,"pb\n", 3);
//     }
//     threesort(stack);
// }

// void pb_low_index(t_general *stack)
// {
//     int     i;
//     int     j;
//     t_list *sort;

//     i = listsize(stack->a);
//     j = i;
//     sort = stack->a;
//     while ((sort && (j > 0) )&& listsize(stack->a) > 3)
//     {
//         if (sort->index <= (i / 2))
//         {
//             write(1, "pb\n", 3);
//             ft_pb(stack);
//             sort = stack->a;
//         }
//         else
//         {
//             write(1, "ra\n", 3);
//             ft_ra(stack->a);
//         }
//         j--;
//     }
//     pb_all(stack);
// }
// void target_position_for_a(t_list *a, t_list *b)
// {
//     int     num;
//     t_list *iter_a;
//     t_list *iter_b;

//     iter_a = a;
//     while (iter_a)
//     {
//         num = INT_MAX;
//         iter_b = b;
//         while (iter_b)
//         {
//             if (iter_a->data > iter_b->data && num > iter_b->data)
//             {
//                 num = iter_b->data;
//                 iter_a->target_pos = iter_b->position;
//             }
//             iter_b = iter_b->next;
//         }
//         if (num == INT_MAX)
//         {
//             iter_b = b;
//             num = iter_b->data;
//             while (iter_b)
//             {
//                 iter_a->target_pos = iter_b->position;
//                 iter_b = iter_b->next;
//             }
//             while (iter_b)
//             {
//                 if (iter_b->data < num)  // En küçük değeri bul (en büyük değil)
//                 {
//                     num = iter_b->data;
//                     iter_a->target_pos = iter_b->position;
//                 }
//                 iter_b = iter_b->next;
//             }
//         }
//         iter_a = iter_a->next;
//     }
// }


// void cost_function_for_a(t_general *stack)
// {
//     t_list *temp_a;
//     int     size_b;
//     int     size_a;

//     size_a = listsize(stack->a);
//     size_b = listsize(stack->b);
//     temp_a = stack->a;
//     while (temp_a)
//     {
//         temp_a->cost_a = temp_a->position;
//         temp_a->cost_b = temp_a->target_pos;
//         if (temp_a->position > (size_a / 2))
//             temp_a->cost_a = (size_a - temp_a->position) * -1;
//         if (temp_a->target_pos > (size_b / 2))
//             temp_a->cost_b = (size_b - temp_a->target_pos) * -1;
//         temp_a = temp_a->next;
//     }
// }

// void  findcheapest_for_a(t_general *stack)
// {
//     int     i;
//     int     j;
//     int     num;
//     t_list  *cheapest;
//     t_list  *iter;
    
//     num = 2147483647;
//     iter = stack->a;
//     cheapest = iter;
//     while (iter)
//     {
//         if (iter->cost_a < 0)
//             i = (iter->cost_a * -1);
//         if(iter->cost_b < 0)
//             j = (iter->cost_b * -1);
//         if ((i + j) < num)
//         {
//             num = (i + j);
//             cheapest = iter;
//         }
//         iter = iter->next;
//     }
//     move(stack,cheapest);
// }


// void    pb_low_cost(t_general *stack)
// {
//     ft_pb(stack);
//     write(1, "pb\n", 3);
//     while (listsize(stack->a) > 3 && stack->b->data != 23)
//     {
//         position(stack);
//         target_position_for_a(stack->a, stack->b);
//         cost_function_for_a(stack);
//         position(stack);

//         //findcheapest_for_a(stack);
//         write(1, "pb\n", 3);
// 	    ft_pb(stack);
//         position(stack);
//         target_position_for_a(stack->a, stack->b);
//         cost_function_for_a(stack);

//     }
//     //threesort(stack);
    


// }

// void bigsort(t_general *stack)
// {
//     indx(stack->a);
//     pb_low_cost(stack);
//     //pb_low_index(stack);
//     // while (stack->b)
//     // {
//     //     position(stack);
//     //     target_position(stack->b,stack->a);
//     //     cost_function(stack);
//     //     findcheapest(stack);
//     //     write(1, "pa\n", 3);
// 	//     ft_pa(stack);
//     // }


//     // t_list *temp = stack->a;
//     // t_list *min_node = temp;
//     // while (temp)
//     // {
//     //     if (temp->index < min_node->index)
//     //         min_node = temp;
//     //     temp = temp->next;
//     // }

//     // position(stack);
//     // int min_pos = min_node->position;
//     // int size_a = listsize(stack->a);


//     // if (min_pos <= size_a / 2)
//     // {
//     //     while (stack->a->index != 1)
//     //     {
//     //         write(1, "ra\n", 3);
//     //         ft_ra(stack->a);
//     //     }
//     // }
//     // else
//     // {
//     //     while (stack->a->index != 1)
//     //     {
//     //         write(1, "rra\n", 4);
//     //         ft_rra(&stack->a);
//     //     }
//     // }
// }


#include "pushswap.h"

// void	threesort(t_list *stack_a)
// {
// 	t_list	*node;

// 	node = stack_a;
// 	if (is_sorted(stack_a))
// 		return ;
// 	if (min_node(stack_a) == ft_lstlast(stack_a))
// 	{
// 		if (node->index > node->next->index)
// 		{
// 			ft_sa(stack_a);
// 			ft_rra(stack_a);
// 		}
// 		else
// 			rra(stack_a);
// 	}
// 	else if (node->next->index > node->index)
// 	{
// 		rra(stack_a);
// 		sa(stack_a);
// 	}
// 	else if (ft_lstlast(stack_a)->index > node->index)
// 		sa(stack_a);
// 	else
// 		ra(stack_a);
// }
#include "pushswap.h"

// void indx(t_list *a)
// {
//     int     i;
//     t_list  *iter;
//     t_list *tmp;

//     iter = a;
//     // while (iter)
//     // {
//     //     iter->index = -1;
//     //     iter = iter->next;
//     // }
//     i = 0;
//     while (i <= listsize(a))
//     {
//         iter = a;
//         tmp = NULL;
//         while (iter)
//         {
//             if (iter->index == -1 && (tmp == NULL || iter->data < tmp->data))
//                 tmp = iter;
//             iter = iter->next;
//         }
//         if (tmp)
//             tmp->index = i;
//         i++;
//     }
// }












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
