/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 02:13:20 by jfreitas          #+#    #+#             */
/*   Updated: 2021/04/27 00:33:28 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lists(t_lst **a, t_lst **b)
{
	t_lst *tmp;
	t_lst *btmp;
	int		i;

	if (a)
		tmp = (*a);
	else
		tmp = NULL;
	if (b)
		btmp = (*b);
	else
		btmp = NULL;
	i = 1;
/*	while (tmp)
	{
	//	while (i-- >= 0)
	//	{
			printf("a = %d		", tmp->nb);
			if (!btmp)
				printf("\n");
	//	}
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

	printf("\n---------------------------------------------------\n");*/
}

/*
 * sa or sb: swap -> swap the first 2 elements at the top of stack.
 * Do nothing if there is only one or no elements).
 */

void	sa(t_lst **a, int fd)
{
	int		tmp;


/// delete
		//	printf("\n--->>> %s", "sa\n");
			print_lists(a, 0);
/// delete
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

/// delete
			//printf("\n--->>> %s", "sb\n");
		print_lists(0, b);
/// delete

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

/// delete
		//printf("\n--->>> %s", "ss\n");
	print_lists(a, b);
/// delete

	if (fd == 1)
		ft_putstr_fd("ss\n", fd);
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
	nb = 0;

	if (a && b)
	{
		nb = (*a)->nb;
		tmp = lstnew(nb);
		lstadd_front(b, tmp);
		if ((*a)->next)
			(*a) = (*a)->next;
		else
			free_lst(a);//free((*a));//
	//	free(tmp);

/// delete
		//printf("\n--->>> %s", "pb\n");
		print_lists(a, b);
/// delete

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
	int		nb;

	tmp = NULL;
	nb = 0;
	if (a && b)
	{
		nb = (*b)->nb;
		tmp = lstnew(nb);
		lstadd_front(a, tmp);
		if ((*b)->next)
			(*b) = (*b)->next;
		else
			free_lst(b);//free((*b));//
	//	free(tmp);

/// delete
		//printf("\n--->>> %s", "pa\n");
		print_lists(a, b);
/// delete

		if (fd == 1)
			ft_putstr_fd("pa\n", fd);
	}
}
