/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:55:15 by makpolat          #+#    #+#             */
/*   Updated: 2025/02/19 19:12:26 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list *ft_listcreate(int data)
{
    t_list *node;

    node = (t_list *)malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->data = data;
    node->next = NULL;
    return (node);
}

t_list *ft_lstnew(t_general *stack, int data)
{
    t_list *node;

    node = (t_list *)malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->data = data;
    if (stack->a == NULL)
    {
        stack->a = node;
    }
    else
    {
        ft_lstadd_back(stack, node);
    }
    
    node->next = NULL;
    free(node);
    return (stack->a);
}

t_general *addlist(int argc, char **argv)
{
    int i;
    char **seperate;
    t_general *stack;

    stack = malloc(sizeof(t_general));
    i = 0;
    stack->a = NULL;
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

t_list *ft_lstlast(t_list *lst)
{
    if (lst == NULL)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

void ft_lstadd_back(t_general *stack, t_list *new)
{
    if (!new || !stack)
        return;
    if (stack == NULL)
    {
        stack->a = new;
        new->next = NULL;
    }
    else
        ft_lstlast(stack->a)->next = new;
}

void ft_lstadd_front(t_list **stack, t_list *new)
{
    if (!new)
        return;

    new->next = *stack;
    *stack = new;
}
