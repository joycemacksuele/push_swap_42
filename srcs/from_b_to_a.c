/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 00:08:21 by jfreitas          #+#    #+#             */
/*   Updated: 2021/05/01 00:04:48 by whoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Those functions are part of the from_b_to_a functions, that was way bigger
 * than 25 lines so I need to devide it.
 */

void	before_check_next_2_numbers(t_lst **a, t_lst **b)
{
	if ((*a) && ((*a)->next && (*a)->nb > (*a)->next->nb)
		&& ((*b)->next && (*b)->nb < (*b)->next->nb))
		ss(a, b, 1);
	else if ((*a)->nb > (*a)->next->nb)
		sa(a, 1);
	if ((*b) && lst_is_sort((*b), -1) == -1)
	{
		if (!(*b)->next->next)
			sb(b, 1);
	}
	else if ((*b) && lst_is_sort((*b), -1) == 0)
	{
		while ((*b))
			pa(a, b, 1);
	}
}

/*
 * checking which of the 2 biggest numbers are closer to the head of b, to then
 * send it to the top (if it is not already the head).
 * It checks the 2 numbers positions using their indexes, that was obtained
 * with the function search_bigger_number.
 */

void	rotate_b(t_lst **b, int i1, int i2)
{
	if (i1 < ((lstlen(b) - 1) - i2))
		rb(b, 1);
	else if (i1 >= ((lstlen(b) - 1) - i2))
		rrb(b, 1);
}

/*
 * It searches the second biggest number on the stack b and also get it's index.
 */

int	bigger_nb_2(t_lst **b, int bigger1, int *bigger2)
{
	t_lst	*head;
	int		i2;

	i2 = 0;
	head = (*b);
	if (!head)
		return (-1);
	i2 = search_bigger_number(&head, 0, bigger1);
	*bigger2 = head->nb;
	return (i2);
}

/*
 * It searches the biggest number on the stack b and also get it's index.
 */

int	bigger_nb(t_lst **b, int *bigger1)
{
	t_lst	*head;
	int		i1;

	i1 = 0;
	head = (*b);
	if (!head)
		return (-1);
	i1 = search_bigger_number(&head, -1, -1);
	*bigger1 = head->nb;
	return (i1);
}
