/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:01:49 by jfreitas          #+#    #+#             */
/*   Updated: 2021/04/25 04:28:42 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstclear(t_lst **lst, void (*del)(void *))
{
	t_lst	*tmp;

	if (!(*lst) || !del)
		return ;
	while ((*lst))
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
		tmp = NULL;
	}
}

/*t_lst	*lst_before_last(t_lst *a_or_b)
{
	t_lst	*last;

	last = a_or_b;
	if (!a_or_b || !a_or_b->next)
		return (NULL);
//	if (last->next)
//	{
	while (last->next->next)
		last = last->next;
//	}
	return (last);
}*/

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
