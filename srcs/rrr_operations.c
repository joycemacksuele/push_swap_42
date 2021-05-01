/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 02:13:20 by jfreitas          #+#    #+#             */
/*   Updated: 2021/05/01 03:40:49 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * rrr: rra and rrb at the same time.
 */

void	rrr(t_lst **a, t_lst **b, int fd)
{

	if ((*a)->next && (*b)->next)
	{
		rra(a, 0);
		rrb(b, 0);
	}
	//print_lists(a, b);
	if (fd == 1)
		ft_putstr_fd("rrr\n", fd);
}

/*
 * rra or rrb: reverse rotate -> shift down all elements of stack a by 1.
 * The last element becomes the first one.
 *
 * 1. new is set to point to the second link of the linked list.
 * 2. loop on *new (which starts from second link), and set last to it.
 * 3. setting last's last pointer to NULL.
 * 4. the next link of *new (the 2nd link of the linked list) is now pointing
 *    to the head of *a.
 * 5. the head of the list *a is now equal to the head of *new.
 */

void	rra(t_lst **a, int fd)
{
	t_lst	*last;
	t_lst	*new;

	last = (*a);
	new = (*a)->next;
	while (new->next)
	{
		last = new;
		new = new->next;
	}
	last->next = NULL;
	new->next = (*a);
	(*a) = new;
	//print_lists(a, NULL);
	if (fd == 1)
		ft_putstr_fd("rra\n", fd);
}


void	rrb(t_lst **b, int fd)
{
	t_lst	*last;
	t_lst	*new;

	last = (*b);
	new = (*b)->next;
	while (new->next)
	{
		last = new;
		new = new->next;
	}
	last->next = NULL;
	new->next = (*b);
	(*b) = new;
	//print_lists(NULL, b);
	if (fd == 1)
		ft_putstr_fd("rrb\n", fd);
}
