/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 00:08:21 by jfreitas          #+#    #+#             */
/*   Updated: 2021/03/24 02:03:32 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Pour 3 values = normal: 1 or 2 ... max 3 opérations
Pour 5 values = normal 5 to 9 and  max 12
Pour 100 values = barème de 1 à 5
  - moins de 700: 5 this one
  - moins de 900: 4
  - moins de 1100: 3
  - moins de 1300: 2
  - moins de 1500: 1:
Pour 500 values = barème de 1 à 5
  - moins de 5300: 5 this one
  - moins de 7000: 4
  - moins de 8500: 3
  - moins de 10000: 2
  - moins de 11500: 1
*/


/*
 * pa or pb: push -> take the first element at the top of the other stack and
 * put it at the top of the current stack.
 * Do nothing if the other stack is empty.
 */

void	pa_pb(t_lst **a, t_lst **b, char a_or_b, int fd)
{
	t_lst	*tmp;
	int		nb;

	tmp = NULL;
	if (a && b)
	{
		if (a_or_b == 'a')
		{
			nb = (*b)->nb;
			tmp = lstnew(nb);
			lstadd_front(a, tmp);
			lstdelone(*b);
			/*if ((*b)->next)
				(*b) = (*b)->next;
			else
				*b = NULL;*/
			if (fd == 1)
				ft_putstr_fd("pa\n", fd);
		}
		else if (a_or_b == 'b')
		{
			nb = (*a)->nb;
			tmp = lstnew(nb);
			lstadd_front(b, tmp);
			lstdelone(*a);
			if (fd == 1)
				ft_putstr_fd("pb\n", fd);
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
	sa_sb(a, b, 'a', 0);
	sa_sb(a, b, 'b', 0);
	if (fd == 1)
		ft_putstr_fd("ss\n", fd);
}


/*
 * sa or sb: swap -> swap the first 2 elements at the top of stack.
 * Do nothing if there is only one or no elements).
 */

void	sa_sb(t_lst **a, t_lst **b, char a_or_b, int fd)
{
	int	tmp;

	if (a_or_b == 'a' && a)
	{
		(void)b;
		tmp = (*a)->nb;
		(*a)->nb = (*a)->next->nb;
		(*a)->next->nb = tmp;
		if (fd == 1)
			ft_putstr_fd("sa\n", fd);
	}
	else if (a_or_b == 'b' && b)
	{
		(void)a;
		tmp = (*b)->nb;
		(*b)->nb = (*b)->next->nb;
		(*b)->next->nb = tmp;
		if (fd == 1)
			ft_putstr_fd("sb\n", fd);
	}
}

int	lst_is_sort(t_lst *a_or_b)
{
	while (a_or_b)
	{
		printf("%d\n", a_or_b->nb);
		a_or_b = a_or_b->next;
	}
	printf("lst is sorted!!!!\n");


	while (a_or_b)
	{
		if (a_or_b->next && a_or_b->nb > a_or_b->next->nb)
			return (-1);
		a_or_b = a_or_b->next;
	}
	return (0);
}

void	sort_1(t_lst **a, t_lst **b)
{
	int	i;

	i = 0;
	(void)b;
	while (1)
	{
		if ((*a)->nb > (*a)->next->nb && (*a)->nb < (*a)->next->next->nb)
			sa_sb(a, b, 'a', 1);
//		if ((*a)->nb < (*a)->next->nb && (*a)->nb > (*a)->next->next->nb)
//			rra(a, b, 'a', 1);
//		if ((*a)->nb > (*a)->next->nb && (*a)->nb > (*a)->next->next->nb)
//			ra(a, b, 'a', 1);
		if (lst_is_sort(*a) == 0)
			break ;
	}

}
