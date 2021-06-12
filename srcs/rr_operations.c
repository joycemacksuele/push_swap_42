/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 02:13:20 by jfreitas          #+#    #+#             */
/*   Updated: 2021/06/10 18:06:20 by jfreitas         ###   ########.fr       */
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
 *
 * It basically puts the head of the list a or b to tmp, then goes sets the
 * current list's head to it's own next link, and lastly add to the end of it,
 * the tmp node just created.
 */

void	ra(t_lst **a, int fd)
{
	t_lst	*tmp;

	if ((*a))
	{
		tmp = (*a);
		(*a) = (*a)->next;
		tmp->next = NULL;
		lstadd_back(a, tmp);
	}
	if (fd == 1)
		ft_putstr_fd("ra\n", fd);
}

void	rb(t_lst **b, int fd)
{
	t_lst	*tmp;

	if ((*b))
	{
		tmp = (*b);
		(*b) = (*b)->next;
		tmp->next = NULL;
		lstadd_back(b, tmp);
	}
	if (fd == 1)
		ft_putstr_fd("rb\n", fd);
}
