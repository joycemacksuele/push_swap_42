/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 02:13:20 by jfreitas          #+#    #+#             */
/*   Updated: 2021/04/27 00:42:20 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * rr: ra and rb at the same time.
 */

void	rr(t_lst **a, t_lst **b, int fd)
{
	if ((*a)->next && (*b)->next)
	{
		ra(a, 0);
		rb(b, 0);
	}

/// delete
	//	printf("\n--->>> %s", "rr\n");
	print_lists(a, b);
/// delete

	if (fd == 1)
		ft_putstr_fd("rr\n", fd);
}

/*
 * ra or rb: rotate -> shift up all elements of stack a by 1. The first
 * element becomes the last one.
 * Here int tmp is set to be the hed of the list a, then go to the next link of
 * the list a, create a new list with tmp on it (the number on head of a), and
 * lastly, link this new list to the back of the list a and free the list just
 * created.
 */

void	ra(t_lst **a, int fd)
{
	int		tmp;
	t_lst	*new;

	if ((*a))
	{
		tmp = (*a)->nb;
		(*a) = (*a)->next;
		new = lstnew(tmp);
		lstadd_back(a, new);
//		free(new);
	}

/// delete
		//printf("\n--->>> %s", "ra\n");
	print_lists(a, NULL);
/// delete

	if (fd == 1)
		ft_putstr_fd("ra\n", fd);
}

void	rb(t_lst **b, int fd)
{
	int		tmp;
	t_lst	*new;

	if ((*b))
	{
		tmp = (*b)->nb;
		(*b) = (*b)->next;
		new = lstnew(tmp);
		lstadd_back(b, new);
	//	free_lst(&new);
	}

/// delete
		//printf("\n--->>> %s", "rb\n");
	print_lists(NULL, b);
/// delete

	if (fd == 1)
		ft_putstr_fd("rb\n", fd);
}
