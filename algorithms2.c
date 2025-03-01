/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:02:45 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/01 13:00:32 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "pushswap.h"


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


// void target_position_for_a(t_list *a, t_list *b)
// {
//     t_list *iter_a;
//     t_list *iter_b;

//     iter_a = b;
//     while (iter_a)
//     {
//         int num = INT_MAX;
//         iter_b = a;
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
//             iter_a->target_pos = iter_b->position;
//             while (iter_b)
//             {
//                 if (iter_b->data < num)
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


// void    cost_function_for_a(t_general *stack)
// {
//     t_list *temp_a;
//     int     size_b;
//     int     size_a;

//     size_a = listsize(stack->a);
//     size_b = listsize(stack->b);
//     temp_a = stack->a;
//     while (temp_a)
//     {
//         temp_a->a_cost_a = temp_a->position;
//         temp_a->a_cost_b = temp_a->target_pos;
//         if (temp_a->position > size_a / 2)
//             temp_a->a_cost_a = (size_a - temp_a->position) * -1;
//         if (temp_a->target_pos > size_b / 2)
//             temp_a->a_cost_b = (size_b - temp_a->target_pos) * -1;
//         printf("temp->data %d temp->a_cost_a: %d\n", temp_a->data, temp_a->target_pos);
//         temp_a = temp_a->next;
//     }
// }

// t_list  *findcheapest_for_a(t_general *stack)
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
//         if (iter->a_cost_a < 0)
//             i = (iter->a_cost_a * -1);
//         if(iter->a_cost_b < 0)
//             j = (iter->a_cost_b * -1);
//         if ((i + j) < num)
//         {
//             num = (i + j);
//             cheapest = iter;
//         }
//         iter = iter->next;
//     }
//     return (cheapest);
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
//     write(1, "pb\n", 3);
// 	ft_pb(stack);
// }


// void pb_all(t_general *stack)
// {
//     t_list *cheap;
//     ft_pb(stack);
//     write(1 ,"pb\n", 3);
//     while (listsize(stack->a) > 3)
//     {
//         cheap = findcheapest_for_a(stack);
//         cost_function_for_a(stack);
//         position(stack);
//         target_position_for_a(stack->b, stack->a);
//         cost_function_for_a(stack);
//         move(stack, cheap);
//     }
// }

