/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:34:19 by makpolat          #+#    #+#             */
/*   Updated: 2025/02/22 18:06:36 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	maxcheck(long k, char *seperate[], int *ptr, int sign)
{
	k = (sign * k);
	if ((k > 2147483647) || (k < -2147483648))
	{
		free_all(seperate);
		free(ptr);
		error("Error\n");
	}
}

void	signerror(int *ptr, char **seperate)
{
	free(ptr);
	free_all(seperate);
	error("Error\n");
}

int	ft_atoi(const char *str, int *ptr, char **seperate)
{
	long	k;
	int		sign;

	k = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str) == 1)
	{
		if (*str == '-' || *str == '+')
			signerror(ptr, seperate);
		k = k * 10 + (*str - 48);
		maxcheck(k, seperate, ptr, sign);
		str++;
	}
	return (sign * k);
}

void	error(char *message)
{
	write(1, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}
