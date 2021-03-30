/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 02:13:33 by jfreitas          #+#    #+#             */
/*   Updated: 2021/03/30 02:28:58 by jfreitas         ###   ########.fr       */
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

typedef struct s_opts
{
	char			*opt;
	struct s_opts	*next;
}					t_opts;

int g_count_operations;
/*----------------------------------------------------------------------------*/

/*
 * push_swap
 */
void	push_swap(t_lst **a, t_lst **b, int ac);
int		is_sort(char **av);
void	pick_algo(t_lst **a, t_lst **b, int ac);

/* Errors */
int		not_int(char **av);
int		find_doubles(char **av);
int		handle_wrong_ac(int ac);

/* push_swap rebuil list functions from libft */
t_lst	*lstnew(int nb);
t_lst	*lstlast(t_lst *a_or_b);
void	lstadd_back(t_lst **a_or_b, t_lst *tmp);
void	lstadd_front(t_lst **a_or_b, t_lst *new);
void	lstdelone(t_lst *lst);

/* push swap lst management */
t_lst	*create_lst(char **av);
int		lst_is_sort(t_lst *a_or_b, int reverse);
void	free_lst(t_lst **a);
int		lstlen(t_lst **lst);

/* Picking algorithm */
int     search_lower_number(t_lst **lower, int checker, int lower1);
void	sort_max_3(t_lst **lst, char a_or_b);
void	sort_max_12(t_lst **a, t_lst **b);
void	sort_max_100(t_lst **a, t_lst **b);

/* Operations */
void	sa_sb(t_lst **lst, char a_or_b, int fd);
void	ss(t_lst **a, t_lst **b, int fd);
void	pa(t_lst **a, t_lst **b, int fd);
void	pb(t_lst **a, t_lst **b, int fd);
void	ra_rb(t_lst **lst, char a_or_b, int fd);
void	rr(t_lst **a, t_lst **b, int fd);
void	rra_rrb(t_lst **lst, char a_or_b, int fd);
void	rrr(t_lst **a, t_lst **b, int fd);

/*----------------------------------------------------------------------------*/

/*
 * checker
 */
void	checker(t_lst **a, t_lst **b, int ac);

/* checker list management */
t_list	*create_list_with_operations(char *line);
void	free_list(t_list **operations);

#endif
