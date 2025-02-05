/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:17:20 by makpolat          #+#    #+#             */
/*   Updated: 2025/02/05 15:26:26 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void tekrarcheck(t_list **stack_a)  // aynı sayıdan başka var mı kontrolü
{
	int i = 0;
	int k = 0;

	while (stack_a[i]->next != NULL)
	{
		k = i + 1;
		while (stack_a[k]->next != NULL)
		{
			if (stack_a[i]->data == stack_a[k]->data)
				error("ayni sayidan birden cok kez bulundu\n");
			k++;
		}
		i++;
	}
}

void	sayicheck(char *seperate[]) // girilen değerlerin arasında sayı yok ise kontrolü
{
	int i = 0;
	int k = 0;

	while (seperate[i])
	{
		k = 0;
		while (seperate[i][k])
		{
			if (ft_isdigit(seperate[i][k]) == 0)
				error("Bu bir sayi değildir.\n");
			k++;
		}
		i++;
	}
}

t_list **sayidonustur(int argc, char *seperate[])    // karakterleri sayıya dönüştürme fonksiyonu
{
	int i;
	t_list **stack_a;

	stack_a = (t_list **)malloc(sizeof(t_list) * argc);
	if (stack_a == NULL)
		error("malloc oluşmadi\n");
	i = 0;
	while (seperate[i])
	{
		stack_a[i] = (t_list *)malloc(sizeof(t_list));
		stack_a[i]->data = ft_atoi(seperate[i]);
		stack_a[i]->next = NULL;
		i++;
	}
	tekrarcheck(stack_a);
	return (stack_a);
}


void seperate(int argc, char *argv[])   // tırnak içinde gelen argümanları ayırma fonksyionu
{
	char **seperate;
	t_list **stack_a;
	size_t i;

	i = 0;
	while (argv[1][i] != '\0' && argv[1][i] == ' ')	// eğer girilen argüman komple space den oluşuyor ise
		i++;
	if (ft_strlen(argv[1]) == i)
		error("space girmissin knk\n");
	seperate = ft_split(argv[1], ' ');
	argc = 0;
	while(seperate[argc])
		argc++;
	sayicheck(seperate);
	stack_a = sayidonustur(argc, seperate);
	i = 0;
	while(stack_a[i]->next != NULL)
	{
		printf("%d \n",stack_a[i]->data);
		i++;
	}
}
void	sayikontrol2(char *argv[])	// argümanlar normal olarak verilirse sayı dışında bir şey var mı bakmak için
{
	int i;
	int k;

	k = 0;
	i = 1;
	while (argv[i])
	{
		k = 0;
		while (argv[i][k])
		{
			if ((ft_isdigit(argv[i][k]) == 0))
				error("bu bir sayi değil\n");
			k++;
		}
		i++;
	}
}
t_list	**changesayi(int argc, char *argv[])	// eğer argümanlar normal olarak verilirse int e dönüştürme işlemi
{
	int i;
	t_list **stack_a;

	stack_a = (t_list **)malloc(sizeof(t_list) * argc);
	if (stack_a == NULL)
		error("malloc oluşmadi\n");
	i = 0;
	while (argv[i + 1])
	{
		stack_a[i] = (t_list *)malloc(sizeof(t_list));
		stack_a[i]->data = ft_atoi(argv[i + 1]);
		stack_a[i]->next = NULL;
		i++;
	}
	tekrarcheck(stack_a);
	sayikontrol2(argv);
	return (stack_a);
}


int main(int argc, char *argv[])
{
	t_list **deneme;
	int i = 0;
	if (argc == 2)	// argümanlar çift tırnak içerisinde geldiyse
	{
		seperate(argc, argv);
	}
	else if(argc == 1)	// hiç bir argüman girilmediyse
		error("argümansiz çalişir mi\n");
	else	// argümanlar normal olarak girildiyse
	{
		deneme = changesayi(argc,argv);
		while (i < (argc -1))
		{
			printf("%d\n",deneme[i]->data);
			i++;
		}
	}
}
