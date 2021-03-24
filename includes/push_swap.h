/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 02:13:33 by jfreitas          #+#    #+#             */
/*   Updated: 2021/03/24 02:04:56 by jfreitas         ###   ########.fr       */
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

/*
 * push_swap
 */
void	push_swap(t_lst **a, t_lst **b, int ac);
int		not_int(char **av);
int		find_doubles(char **av);

/* push_swap list */
t_lst	*lstnew(int nb);
void	lstadd_back(t_lst **a_or_b, t_lst *tmp);
void	lstadd_front(t_lst **a_or_b, t_lst *new);
t_lst	*lstlast(t_lst *a_or_b);
void	lstdelone(t_lst *lst);

t_lst	*create_list(char **av);
void	free_list_a(t_lst **a);

/* Picking algorithm */
void	sort_1(t_lst **a, t_lst **b);

/* Operations */
void	sa_sb(t_lst **a, t_lst **b, char a_or_b, int fd);
void	ss(t_lst **a, t_lst **b, int fd);
void	pa_pb(t_lst **a, t_lst **b, char a_or_b, int fd);
void	ra_rb(t_lst **a, t_lst **b, char a_or_b, int fd);
void	rr(t_lst **a, t_lst **b, int fd);
void	rra_rrb(t_lst **a, t_lst **b, char a_or_b, int fd);
void	rrr(t_lst **a, t_lst **b, int fd);

/*----------------------------------------------------------------------------*/

/*
 * checker
 */
void	checker(t_lst **a, t_lst **b, int ac);

#endif
