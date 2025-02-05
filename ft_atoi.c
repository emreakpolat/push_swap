/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:34:19 by makpolat          #+#    #+#             */
/*   Updated: 2025/02/05 19:03:13 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
		k = k * 10 + (*str - 48);
		str++;
		if ((k > 2147483647) || (k < -2147483648))
		{
			free_all(seperate);
			free(ptr);
			error("Sayi sinirlarin disindaydi\n"); // Error'a girerse exit ile çıkar ve program sonlanır
		}
	}
	return (sign * k);
}
void error(char *message)
{
	write(1, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}