/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:34:19 by makpolat          #+#    #+#             */
/*   Updated: 2025/01/27 10:22:48 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_atoi(const char *str)
{
	char	*ptr;
	int		i;
	int		k;
	int		a;

	ptr = (char *)str;
	i = 0;
	k = 0;
	a = 1;
	while (ptr[i] == ' ' || (ptr[i] >= '\t' && ptr[i] <= '\r'))
		i++;
	if (ptr[i] == '-')
	{
		a = -1;
		i++;
	}
	else if (ptr[i] == '+')
		i++;
	while (ft_isdigit(ptr[i]) == 1)
	{
		k = k * 10 + (ptr[i] - 48);
		i++;
	}
	return (a * k);
}
