/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:34:19 by makpolat          #+#    #+#             */
/*   Updated: 2025/02/07 12:52:39 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
void maxcheck(long k, char *seperate[], int *ptr, int sign)
{
	k = (sign * k);
	if ((k > 2147483647) || (k < -2147483648))
	{
		free_all(seperate);
		free(ptr);
		error("Sayi sinirlarin disindaydi\n"); // Error'a girerse exit ile çıkar ve program sonlanır
	}
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
	if (*str == 0)
		error("bos isaret gimeee\n");
	while (ft_isdigit(*str) == 1)
	{
		k = k * 10 + (*str - 48);
		maxcheck(k, seperate, ptr, sign);
		str++;
	}
	return (sign * k);
}
void error(char *message)
{
	write(1, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}