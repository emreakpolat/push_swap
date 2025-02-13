/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:20:43 by makpolat          #+#    #+#             */
/*   Updated: 2025/02/13 17:04:12 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef pushswap_h
#define pushswap_h

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_list{
    int data;
    struct s_list *next;
}t_list;

typedef struct s_general{
    
    t_list *a;
    t_list *b;

}t_general;


int	ft_atoi(const char *str, int *ptr, char *seperate[]);
int	ft_isdigit(int c);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char *pushswap(int argc, char *argv[]);
void error(char *message);
int ft_strcmp(const char *str1, const char *str2);
char	**free_all(char **s);
void changesayi(int argc, char *argv[]);
void	sayikontrol2(char *argv[], int *ptr);
void seperate(int argc, char *argv[]);
int *sayidonustur(int argc, char *seperate[]);
void	sayicheck(char *seperate[]);
void tekrarcheck(int *ptr, int len, char *seperate[]);
void	control(int argc, char *argv[]);

// t_list addlistchar(int argc, char **argv);
int	ft_atoilst(const char *str);
t_general *addlist(int argc, char **argv);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_general **stack, t_list *new);
t_list	*ft_lstnew(t_general *stack, int data);

#endif