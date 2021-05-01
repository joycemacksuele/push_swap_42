/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 02:13:20 by jfreitas          #+#    #+#             */
/*   Updated: 2021/05/01 00:20:49 by whoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Funtion only for test purposes.
 */

void	print_lists(t_lst **a, t_lst **b)
{
	t_lst	*tmp;
	t_lst	*btmp;
	int		i;

	tmp = (*a);
	btmp = (*b);
	i = 1;
	while (tmp)
	{
		while (i-- >= 0)
		{
			printf("a = %d		", tmp->nb);
			if (!btmp)
				printf("\n");
		}
		if (btmp)
		{
			printf("		b = %d\n", btmp->nb);
			btmp = btmp->next;
		}
		tmp = tmp->next;
	}
	while (btmp)
	{
		printf("					b = %d\n", btmp->nb);
		btmp = btmp->next;
	}
	printf("\n---------------------------------------------------\n");
}

/*
 * sa or sb: swap -> swap the first 2 elements at the top of stack.
 * Do nothing if there is only one or no elements).
 */

void	sa(t_lst **a, int fd)
{
	int		tmp;

	//print_lists(a, 0);
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
	int		tmp;

	//print_lists(0, b);
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
	//print_lists(a, b);
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
		//print_lists(a, b);
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
		//print_lists(a, b);
		if (fd == 1)
			ft_putstr_fd("pa\n", fd);
	}
}
