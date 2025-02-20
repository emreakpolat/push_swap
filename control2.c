/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:48:12 by makpolat          #+#    #+#             */
/*   Updated: 2025/02/20 17:48:31 by makpolat         ###   ########.fr       */
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
