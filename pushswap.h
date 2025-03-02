/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:20:43 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/02 16:07:30 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_general
{
	t_list	*a;
	t_list	*b;
}	t_general;

int			ft_isdigit(int c);
int			is_sort(t_list *stack);
int			ft_atoilst(const char *str);
int			maximum_bits(t_list *stack);
int			ft_strcmp(const char *str1, const char *str2);
int			ft_atoi(const char *str, int *ptr, char *seperate[]);
char		**free_all(char **s);
char		*ft_strdup(const char *s1);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		error(char *message);
void		ft_ra(t_list *stack);
void		ft_rra(t_list **stack);
void		ft_sb(t_general *stack);
void		ft_sa(t_general *stack);
void		ft_pb(t_general *stack);
void		ft_pa(t_general *stack);
void		sorting(t_general *stack);
void		foursort(t_general *stack);
void		fivesort(t_general *stack);
void		position(t_general *stack);
void		threesort(t_general *stack);
void		number_check(char *seperate[]);
void		control(int argc, char *argv[]);
void		ft_lstadd_front(t_list **stack, t_list *new);
void		repeat_check(int *ptr, int len, char *seperate[]);
void		bigsort(t_general *stack, int i, int j, int stack_size);
size_t		ft_strlen(const char *s);
t_list		*ft_lstlast(t_list *lst);
t_general	*addlist(int argc, char **argv);
t_list		*ft_lstnew(t_general *stack, int data);

#endif