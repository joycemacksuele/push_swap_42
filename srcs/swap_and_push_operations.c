/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 02:13:20 by jfreitas          #+#    #+#             */
/*   Updated: 2021/03/28 17:22:24 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * sa or sb: swap -> swap the first 2 elements at the top of stack.
 * Do nothing if there is only one or no elements).
 */

void	sa_sb(t_lst **lst, char a_or_b, int fd)
{
	int	tmp;

	tmp = (*lst)->nb;
	(*lst)->nb = (*lst)->next->nb;
	(*lst)->next->nb = tmp;
	if (fd == 1)
	{
		if (a_or_b == 'a')
		{
			ft_putstr_fd("sa\n", fd);
			g_count_operations++;
		}
		else if (a_or_b == 'b')
		{
			ft_putstr_fd("sb\n", fd);
			g_count_operations++;
		}
	}
}

/*
 * ss: sa and sb at the same time.
 */

void	ss(t_lst **a, t_lst **b, int fd)
{
//ss can be called when there is no 2 numbers to swap on one of the stacks. Handle
//that here or just dont call ss if one of the stacks dont have at least 2 numbers?
	sa_sb(a, 'a', 0);
	sa_sb(b, 'b', 0);
	if (fd == 1)
	{
		ft_putstr_fd("ss\n", fd);
		g_count_operations++;
	}

}

/*
 * pb: push a -> take the first element at the top of a and put it at the top
 *  of b. Do nothing if the other stack is empty.
 */

void	pb(t_lst **a, t_lst **b, int fd)
{
	t_lst	*tmp;
	int		nb;

	tmp = NULL;
	if (a && b)
	{
		nb = (*a)->nb;
		tmp = lstnew(nb);
		lstadd_front(b, tmp);
		if ((*a)->next)
			(*a) = (*a)->next;
		else
			free_lst(a);
		//	(*a) = NULL;

	/*	// test -------------------
		while ((*a))
		{
			printf("a after = %d\n", (*a)->nb);
			(*a) = (*a)->next;
		}
		printf("\n\n");
		while ((*b))
		{
			printf("b after = %d\n", (*b)->nb);
			(*b) = (*b)->next;
		}
		// test -------------------*/
		if (fd == 1)
		{
			ft_putstr_fd("pb\n", fd);
			g_count_operations++;
		}
	}
}

/*
 * pa: push a -> take the first element at the top of b and put it at the top
 *  of a. Do nothing if the other stack is empty.
 */

void	pa(t_lst **a, t_lst **b, int fd)
{
	t_lst	*tmp;
	int		nb;

	tmp = NULL;
	if (a && b)
	{
//		(*b) = lstnew(5);
		nb = (*b)->nb;
		tmp = lstnew(nb);
		lstadd_front(a, tmp);
		if ((*b)->next)
			(*b) = (*b)->next;
		else
			free_lst(b);
		//	(*b) = NULL;

	/*	//test ------------------
		while ((*a))
		{
			printf("a = %d\n", (*a)->nb);
			(*a) = (*a)->next;
		}
		printf("\n\n");
		while ((*b))
		{
			printf("b = %d\n", (*b)->nb);
			(*b) = (*b)->next;
		}
		//test ------------------*/
		if (fd == 1)
		{
			ft_putstr_fd("pa\n", fd);
			g_count_operations++;
		}
	}
}
