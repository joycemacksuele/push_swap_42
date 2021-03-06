/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:01:49 by jfreitas          #+#    #+#             */
/*   Updated: 2021/04/30 03:25:54 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Same or almost same as the lists functions of libft but here, for the t_lst
 * list, not the libft t_list list.
 */

t_lst	*lstlast(t_lst *a_or_b)
{
	t_lst	*last;

	last = a_or_b;
	if (!a_or_b)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}

void	lstadd_front(t_lst **a_or_b, t_lst *new)
{
	if (!new)
		return ;
	new->next = *a_or_b;
	*a_or_b = new;
}

void	lstadd_back(t_lst **a_or_b, t_lst *tmp)
{
	t_lst	*last;

	last = lstlast(*a_or_b);
	if (!tmp)
		return ;
	if (!last)
		lstadd_front(a_or_b, tmp);
	else
		last->next = tmp;
}

t_lst	*lstnew(int nb)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}
