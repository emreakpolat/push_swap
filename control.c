/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:31:05 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/02 13:30:47 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*push_atoi(int argc, char *seperate[])
{
	int	i;
	int	*ptr;

	ptr = (int *)malloc(sizeof(int) * argc);
	if (ptr == NULL)
		error("Error\n");
	i = 0;
	while (seperate[i])
	{
		ptr[i] = ft_atoi(seperate[i], ptr, seperate);
		i++;
	}
	repeatcheck(ptr, i, seperate);
	return (ptr);
}

void	seperate(int argc, char *argv[])
{
	char	**seperate;
	int		*ptr;
	size_t	i;

	i = 0;
	while (argv[1][i] != '\0' && argv[1][i] == ' ')
		i++;
	if (ft_strlen(argv[1]) == i)
		error("Error\n");
	seperate = ft_split(argv[1], ' ');
	argc = 0;
	while (seperate[argc])
		argc++;
	intcheck(seperate);
	ptr = push_atoi(argc, seperate);
	free(ptr);
	free_all(seperate);
}

void	intcontrol2(char *argv[], int *ptr)
{
	int	i;
	int	k;

	k = 0;
	i = 1;
	while (argv[i])
	{
		k = 0;
		while (argv[i][k])
		{
			if ((ft_isdigit(argv[i][k]) == 0))
			{
				free(ptr);
				error("Error\n");
			}
			k++;
		}
		i++;
	}
}

void	changeinteger(int argc, char *argv[])
{
	int	i;
	int	*ptr;

	ptr = (int *)malloc(sizeof(int) * argc);
	if (ptr == NULL)
		error("Error\n");
	i = 0;
	while (argv[i + 1])
	{
		ptr[i] = ft_atoi(argv[i + 1], ptr, NULL);
		i++;
	}
	repeatcheck(ptr, i, NULL);
	intcontrol2(argv, ptr);
	free(ptr);
}

void	control(int argc, char *argv[])
{
	if (argc == 1)
		exit(0);
	else if (argc == 2)
	{
		seperate(argc, argv);
	}
	else
		changeinteger(argc, argv);
}
