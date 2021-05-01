/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 02:13:33 by jfreitas          #+#    #+#             */
/*   Updated: 2021/05/02 01:32:31 by jfreitas         ###   ########.fr       */
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

typedef struct s_dumb
{
	int		pa_or_pb;
	int		ra_or_rra;
	char	**chunk;
	char	*pnbs[2];
}			t_dumb;

/*
 * ONLY for test purposes
 */
void			print_lists(t_lst **a, t_lst **b);

/*
 * push_swap
 */
void			push_swap(t_lst **a, t_lst **b, int ac);
int				is_sort(char **av, int error);
void			pick_algo(t_lst **a, t_lst **b, int ac);

/*
 * Errors
 */
int				not_int(char **av);
int				find_doubles(char **av);
int				handle_wrong_ac(int ac);

/*
 * push_swap rebuilt list functions from libft
 */
t_lst			*lstnew(int nb);
t_lst			*lstlast(t_lst *a_or_b);
t_lst			*lst_before_last(t_lst *a_or_b);
void			lstadd_back(t_lst **a_or_b, t_lst *tmp);
void			lstadd_front(t_lst **a_or_b, t_lst *new);
void			lstclear(t_lst **lst, void (*del)(void *));

/*
 * push swap lst management
 */
t_lst			*create_lst(char **av);
t_list			*create_list_2(char *line);
int				lst_is_sort(t_lst *a_or_b, int reverse);
void			free_lst(t_lst **a_or_b);
int				lstlen(t_lst **lst);

/*
 * Picking algorithm
 */
void			sort_max_3(t_lst **a);
void			sort_max_5(t_lst **a, t_lst **b);
void			sort_max_100(t_lst **a, t_lst **b);
void			sort_max_500(t_lst **a, t_lst **b);
char			**save_stack_to_array(t_lst **a_or_b, int len);
char			**sort_array(char **a_or_b);
/*
 * From stack b to stack a functions
 */
int				search_bigger_number(t_lst **head, int checker, int bigger1);
int				bigger_nb(t_lst **b, int *bigger1);
int				bigger_nb_2(t_lst **b, int bigger1, int *bigger2);
void			rotate_b(t_lst **b, int i1, int i2);
void			before_check_next_2_numbers(t_lst **a, t_lst **b);
int				nbr_equal_bigger1(t_lst **b, int bigger1, int i1, int i2);
int				nbr_equal_bigger2(t_lst **b, int bigger2, int i1, int i2);
int				do_pa(t_lst **a, t_lst **b, int track_of_pa);
int				if1(t_lst **b, int bigger1, int bigger2);
int				if2(t_lst **b, int i1, int i2);

/*
 * Operations
 */
void			sa(t_lst **a, int fd);
void			sb(t_lst **b, int fd);
void			ss(t_lst **a, t_lst **b, int fd);
void			pa(t_lst **a, t_lst **b, int fd);
void			pb(t_lst **a, t_lst **b, int fd);
void			ra(t_lst **a, int fd);
void			rb(t_lst **b, int fd);
void			rr(t_lst **a, t_lst **b, int fd);
void			rra(t_lst **a, int fd);
void			rrb(t_lst **b, int fd);
void			rrr(t_lst **a, t_lst **b, int fd);

/*
 * checker
 */
int				read_operations(char **av, int ret_gnl);
int				check_operations(char *line);
void			create_lists(char *opt, char **av);
void			run_operations_on_stacks(char *line, t_lst **a, t_lst **b);

#endif
