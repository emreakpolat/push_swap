#include "pushswap.h"

void ft_sa(t_general *stack)
{
    int temp;

    if (stack->a->next == NULL || stack->a == NULL)
        return;

    temp = stack->a->next->data;
    stack->a->next->data = stack->a->data;
    stack->a->data = temp;
}
void ft_sb(t_general *stack)
{
    int temp;

    if (stack->b->next == NULL || stack->b == NULL)
        return;

    temp = stack->b->next->data;
    stack->b->next->data = stack->b->data;
    stack->b->data = temp;
}
void ft_pb(t_general *stack)
{
    if (stack->a == NULL)
        return;
    ft_lstadd_front(&stack->b, ft_listcreate(stack->a->data));
    stack->a = stack->a->next;
}
void ft_pa(t_general *stack)
{
    if (!stack->b)
        return;

    ft_lstadd_front(&stack->a, ft_listcreate(stack->b->data));
    stack->b = stack->b->next;
}
void ft_ra(t_list *stack)
{
    t_list *iter;
    int tmp;
    iter = stack;

    if (!stack)
        return;
    tmp = iter->data;
    while (iter->next)
    {
        iter->data = iter->next->data;
        iter = iter->next;
    }
    iter->data = tmp;
}
void ft_rra(t_list **stack)
{
    t_list *iter;
    t_list *tmp;
    iter = *stack;
    tmp = *stack;
    if (!stack)
        return;
    while (iter->next)
        iter = iter->next;

    while (tmp->next != iter)
        tmp = tmp->next;

    tmp->next = NULL;
    iter->next = *stack;
    *stack= iter;
}

void operator(t_general *stack, char *str)
{
    if (ft_strcmp(str, "sa") == 0)
        ft_sa(stack);
    else if (ft_strcmp(str, "sb") == 0)
        ft_sb(stack);
    else if (ft_strcmp(str, "ss") == 0)
    {
        ft_sa(stack);
        ft_sb(stack);
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
    else if(ft_strcmp(str, "rrb") == 0)
        ft_rra(&stack->b);
    else if(ft_strcmp(str, "rrr") == 0)
    {
        ft_rra(&stack->a);
        ft_rra(&stack->b);
    }
}

