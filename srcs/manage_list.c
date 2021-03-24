/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:01:49 by jfreitas          #+#    #+#             */
/*   Updated: 2021/03/24 01:55:54 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list_a(t_lst **a_or_b)
{
	t_lst	*tmp;

	if (!(*a_or_b))
		return ;
	while ((*a_or_b))
	{
		tmp = *a_or_b;
		*a_or_b = (*a_or_b)->next;
		free(tmp);
		tmp = NULL;
	}

}

/*
 * Create and store arguments in a linked list from  av variable (argv).
 * All the links of the list are malloc() and should be free() once the program
 * exit.
 *
 * @args:
 *		char **av: the arguments of the program call.
 * @return:
 *		t_lst *: a pointer to the head of the list (called a).
 */

t_lst	*create_list(char **av)
{
	t_lst	*a_or_b;
	t_lst	*tmp;

	a_or_b = NULL;
	tmp = NULL;
	while (*av != NULL)
	{
		tmp = lstnew(ft_atoi(*av));// or ft_strdup(*av)??
		lstadd_back(&a_or_b, tmp);
		av++;
	}
	return (a_or_b);
}
