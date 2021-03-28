/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:01:49 by jfreitas          #+#    #+#             */
/*   Updated: 2021/03/28 00:15:52 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstlen(t_lst **lst)
{
	int		len;
	t_lst	*tmp;

	len = 0;
	if (*lst)
	{
		tmp = *lst;
		while (tmp)
		{
			len++;
			tmp = tmp->next;
		}
	}
	return (len);
}

void	free_list(t_lst **a_or_b)
{
	t_lst	*tmp;

	if (!(*a_or_b))
		return ;
	while ((*a_or_b))
	{
		tmp = *a_or_b;
	//	free(&(*a_or_b)->nb); ???? int nb was not allocated
		*a_or_b = (*a_or_b)->next;
		free(tmp);
		tmp = NULL;
	}
}

int	lst_is_sort_reverse(t_lst *a_or_b)
{
	while (a_or_b)
	{

// FOR TESTIG ---------------------------------------
	//	printf("%d\n", a_or_b->nb);
	//	printf("first = %d\n", a_or_b->nb);
// ---------------------------------------------------

		if (a_or_b->next && a_or_b->nb < a_or_b->next->nb)
			return (-1);
		a_or_b = a_or_b->next;
	}
// FOR TESTIG ---------------------------------------
//	printf("lst is sorted!!!!\n");
// --------------------------------------------------
	return (0);
}

int	lst_is_sort(t_lst *a_or_b)
{
	while (a_or_b)
	{

// FOR TESTIG ---------------------------------------
	//	printf("%d\n", a_or_b->nb);
	//	printf("first = %d\n", a_or_b->nb);
// ---------------------------------------------------

		if (a_or_b->next && a_or_b->nb > a_or_b->next->nb)
			return (-1);
		a_or_b = a_or_b->next;
	}
// FOR TESTIG ---------------------------------------
//	printf("lst is sorted!!!!\n");
// --------------------------------------------------
	return (0);
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
