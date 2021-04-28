/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 02:13:33 by jfreitas          #+#    #+#             */
/*   Updated: 2021/04/27 02:06:29 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_lst
{
	int				nb;
	struct s_lst	*next;
}					t_lst;

/*----------------------------------------------------------------------------*/

////// tests
void	print_lists(t_lst **a, t_lst **b);

/*
 * push_swap
 */
void	push_swap(t_lst **a, t_lst **b, int ac);
int		is_sort(char **av, int error);
void	pick_algo(t_lst **a, t_lst **b, int ac);

/* Errors */
int		not_int(char **av);
int		find_doubles(char **av);
int		handle_wrong_ac(int ac);

/* push_swap rebuil list functions from libft */
t_lst	*lstnew(int nb);
t_lst	*lstlast(t_lst *a_or_b);
t_lst	*lst_before_last(t_lst *a_or_b);
void	lstadd_back(t_lst **a_or_b, t_lst *tmp);
void	lstadd_front(t_lst **a_or_b, t_lst *new);
void	lstclear(t_lst **lst, void (*del)(void *));

/* push swap lst management */
t_lst	*create_lst(char **av);
t_list	*create_list_2(char *line);
int		lst_is_sort(t_lst *a_or_b, int reverse);
void	free_lst(t_lst **a_or_b);
int		lstlen(t_lst **lst);

/* Picking algorithm */
void	sort_max_3(t_lst **a);//, t_list **operations);
void	sort_max_12(t_lst **a, t_lst **b);//, t_list **operations);
void	sort_max_100(t_lst **a, t_lst **b);//, t_list **operations);
void	sort_max_500(t_lst **a, t_lst **b);
char	**save_stack_to_array(t_lst **a_or_b, int len);
char	**sort_array(char **a_or_b);
int     search_lower_number(t_lst **lower, int checker, int lower1);


/* Operations */
void	sa(t_lst **a, int fd);//, t_list **operations);
void	sb(t_lst **b, int fd);//, t_list **operations);
void	ss(t_lst **a, t_lst **b, int fd);//, t_list **operations);
void	pa(t_lst **a, t_lst **b, int fd);//, t_list **operations);
void	pb(t_lst **a, t_lst **b, int fd);//, t_list **operations);
void	ra(t_lst **a, int fd);//, t_list **operations);
void	rb(t_lst **b, int fd);//, t_list **operations);
void	rr(t_lst **a, t_lst **b, int fd);//, t_list **operations);
void	rra(t_lst **a, int fd);//, t_list **operations);
void	rrb(t_lst **b, int fd);//, t_list **operations);
void	rrr(t_lst **a, t_lst **b, int fd);//, t_list **operations);

/*----------------------------------------------------------------------------*/

/*
 * checker
 */
void	checker(t_lst **a, t_lst **b, int ac);

/* checker list management */
t_list	*create_list(char **line);
void	free_list(void *operations);

#endif
