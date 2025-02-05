/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:17:20 by makpolat          #+#    #+#             */
/*   Updated: 2025/02/05 12:17:34 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void tekrarcheck(int *ptr)  // aynı sayıdan başka var mı kontrolü
{
	int i = 0;
	int k = 0;

	while (ptr[i])
	{
		k = i + 1;
		while (ptr[k])
		{
			if (ptr[k] == ptr[i])
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

int *sayidonustur(int argc, char *seperate[])    // karakterleri sayıya dönüştürme fonksiyonu
{
	int i;
	int *ptr;

	ptr = (int *)malloc(sizeof(int) * argc);
	if (ptr == NULL)
		error("malloc oluşmadi\n");
	i = 0;
	while (seperate[i])
	{
		ptr[i] = ft_atoi(seperate[i], ptr);
		i++;
	}
	tekrarcheck(ptr);
	return (ptr);
}


void seperate(int argc, char *argv[])   // tırnak içinde gelen argümanları ayırma fonksyionu
{
	char **seperate;
	int *ptr;
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
	ptr = sayidonustur(argc, seperate);
	i = 0;
	while(seperate[i])
	{
		printf("%d \n",ptr[i]);
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
int	*changesayi(int argc, char *argv[])	// eğer argümanlar normal olarak verilirse
{
	int i;
	int *ptr;

	ptr = (int *)malloc(sizeof(int) * argc);
	if (ptr == NULL)
		error("malloc oluşmadi\n");
	i = 0;
	while (argv[i + 1])
	{
		ptr[i] = ft_atoi(argv[i + 1], ptr);
		i++;
	}
	tekrarcheck(ptr);
	sayikontrol2(argv);
	return (ptr);
}


int main(int argc, char *argv[])
{
	int *deneme;
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
			printf("%d\n",deneme[i]);
			i++;
		}
	}
}
