/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 02:13:20 by jfreitas          #+#    #+#             */
/*   Updated: 2021/04/01 04:29:56 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * rrr: rra and rrb at the same time.
 */

void	rrr(t_lst **a, t_lst **b, int fd)
{
//rr can be called when there is no 2 numbers to rotate. Handle that here or
//or just dont call rr if the stack doesnt have at least 2 numbers?
	rra_rrb(a, 'a', 0);
	rra_rrb(b, 'b', 0);
	if (fd == 1)
	{
		ft_putstr_fd("rrr\n", fd);
		g_count_operations++;
	}
}

/*
 * rra or rrb: reverse rotate -> shift down all elements of stack a by 1.
 * The last element becomes the first one.
 *
 * 1. head is set to point to the second link of the linked list.
 * 2. loop on *new (which starts from second link), and set last to it.
 * 3. setting last's last pointer to NULL.
 * 4. the next link of *new (the 2nd link of the linked list) is now pointing
 *    to the head of *lst.
 * 5. the head of the main list *lst is now equal to the head of *new.
 */

void	rra_rrb(t_lst **lst, char a_or_b, int fd)
{
	t_lst	*last;
	t_lst	*new;

	last = *lst;
	new = (*lst)->next;
	while (new->next)
	{
		last = new;
		new = new->next;
	}
	last->next = NULL;
	new->next = (*lst);
	(*lst) = new;
	// test
/*	while ((*lst))
	{
		printf("%d\n", (*lst)->nb);
		(*lst) = (*lst)->next;
	}*/
	// test
	if (fd == 1)
	{
		if (a_or_b == 'a')
		{
			ft_putstr_fd("rra\n", fd);
			g_count_operations++;
		}
		if (a_or_b == 'b')
		{
			ft_putstr_fd("rrb\n", fd);
			g_count_operations++;
		}
	}
}

/*
 * rr: ra and rb at the same time.
 */

void	rr(t_lst **a, t_lst **b, int fd)
{
//rr can be called when there is no 2 numbers to rotate. Handle that here or
//or just dont call rr if the stack doesnt have at least 2 numbers?
	ra_rb(a, 'a', 0);
	ra_rb(b, 'b', 0);
	if (fd == 1)
	{
		ft_putstr_fd("rr\n", fd);
		g_count_operations++;
	}
}

/*
 * ra or rb: rotate -> shift up all elements of stack a by 1. The first
 * element becomes the last one.
 */

void	ra_rb(t_lst **lst, char a_or_b, int fd)
{
	int		tmp;
	t_lst	*new;

	if (!(*lst))
		return ;
	tmp = (*lst)->nb;// tmp = first nb of list
	(*lst) = (*lst)->next;// moving head to next list
	new = lstnew(tmp);// creating new list with the first nb on it
	lstadd_back(lst, new);//adding this new list to the end of the linked list
	if (fd == 1)
	{
		if (a_or_b == 'a')
		{
			ft_putstr_fd("ra\n", fd);
			g_count_operations++;
		}
		if (a_or_b == 'b')
		{
			ft_putstr_fd("rb\n", fd);
			g_count_operations++;
		}

	//	free(new);
	}
}
