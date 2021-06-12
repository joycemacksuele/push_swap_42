/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 02:13:20 by jfreitas          #+#    #+#             */
/*   Updated: 2021/06/11 15:25:18 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * sa or sb: swap -> swap the first 2 elements at the top of stack.
 * Do nothing if there is only one or no elements).
 */

void	sa(t_lst **a, int fd)
{
	int	tmp;

	if ((*a))
	{
		tmp = (*a)->nb;
		(*a)->nb = (*a)->next->nb;
		(*a)->next->nb = tmp;
	}
	if (fd == 1)
		ft_putstr_fd("sa\n", fd);
}

void	sb(t_lst **b, int fd)
{
	int	tmp;

	if ((*b))
	{
		tmp = (*b)->nb;
		(*b)->nb = (*b)->next->nb;
		(*b)->next->nb = tmp;
	}
	if (fd == 1)
		ft_putstr_fd("sb\n", fd);
}

/*
 * ss: sa and sb at the same time.
 */

void	ss(t_lst **a, t_lst **b, int fd)
{
	if ((*a)->next && (*b)->next)
	{
		sa(a, 0);
		sb(b, 0);
	}
	if (fd == 1)
		ft_putstr_fd("ss\n", fd);
}

/*
 * pb: push a -> take the first element at the top of a and put it at the top
 *  of b. Do nothing if the other stack is empty.
 *
 * It basically saves the next link of the wanted stack, then saves the head of
 * this stack to tmp and add it to the front of the other stack. Lastly, it
 * sets the head of the wanted stack to that next link that was first saved.
 */

void	pb(t_lst **a, t_lst **b, int fd)
{
	t_lst	*tmp;
	t_lst	*save_head_a;

	tmp = NULL;
	save_head_a = NULL;
	if (a && b)
	{
		if ((*a)->next)
			save_head_a = (*a)->next;
		tmp = (*a);
		tmp->next = NULL;
		lstadd_front(b, tmp);
		(*a) = save_head_a;
		if (fd == 1)
			ft_putstr_fd("pb\n", fd);
	}
}

/*
 * pa: push a -> take the first element at the top of b and put it at the top
 *  of a. Do nothing if the other stack is empty.
 */

void	pa(t_lst **a, t_lst **b, int fd)
{
	t_lst	*tmp;
	t_lst	*save_head_b;

	tmp = NULL;
	save_head_b = NULL;
	if (a && b)
	{
		if ((*b)->next)
			save_head_b = (*b)->next;
		tmp = (*b);
		tmp->next = NULL;
		lstadd_front(a, tmp);
		(*b) = save_head_b;
		if (fd == 1)
			ft_putstr_fd("pa\n", fd);
	}
}
