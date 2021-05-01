/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_b_to_a_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 00:08:21 by jfreitas          #+#    #+#             */
/*   Updated: 2021/04/30 03:15:01 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Those functions are part of the from_b_to_a functions, that was way bigger
 * than 25 lines so I need to devide it.
 */

int	nbr_equal_bigger1(t_lst **b, int bigger1, int i1, int i2)
{
	if ((*b)->nb == bigger1)
		i1 = i2;
	return (i1);
}

int nbr_equal_bigger2(t_lst **b, int bigger2, int i1, int i2)
{
	if ((*b)->nb == bigger2)
		i2 = i1;
	return (i2);
}

int do_pa(t_lst **a, t_lst **b, int track_of_pa)
{
	pa(a, b, 1);
	return (track_of_pa + 1);
}

int if1(t_lst **b, int bigger1, int bigger2)
{
	if (((*b)->nb != bigger1 && (*b)->nb != bigger2) && ((*b)->next &&
		((*b)->next->nb == bigger1 || (*b)->next->nb == bigger2)))
		return (1);
	return (0);
}

int	if2(t_lst **b, int i1, int i2)
{
	if ((i1 <= 2 || i1 > lstlen(b) / 2) && (i2 <= 2 || i2 > lstlen(b) / 2))
		return (1);
	return (0);
}
