/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:01:49 by jfreitas          #+#    #+#             */
/*   Updated: 2021/03/30 02:26:42 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list **operations)
{
	t_list	*tmp;

	if (!(*operations))
		return ;
	while ((*operations))
	{
		tmp = *operations;
	//	free(&(*a_or_b)->nb); ???? int nb was not allocated
		*operations = (*operations)->next;
		free(tmp);
		tmp = NULL;
	}
}

/*void	lstadd_front_opts(t_opts **a_or_b, t_opts *new)
{
	if (!new)
		return ;
	new->next = *a_or_b;
	*a_or_b = new;
}


t_opts	*lstlast_opts(t_opts *a_or_b)
{
	if (!a_or_b)
		return (NULL);
	while (a_or_b->next)
		a_or_b = a_or_b->next;
	return (a_or_b);
}

void	lstadd_back_opts(t_opts **a_or_b, t_opts *tmp)
{
	t_opts	*last;

	last = lstlast_opts(*a_or_b);
	if (!tmp)
		return ;
	if (!last)
		lstadd_front_opts(a_or_b, tmp);
	else
		last->next = tmp;
}

t_opts	*lstnew_opts(char *line)
{
	t_opts	*new;

	new = (t_opts *)malloc(sizeof(t_opts));
	if (!new)
		return (NULL);
	new->opt = line;
	new->next = NULL;
	return (new);
}*/


/*
 * Create and store the output of the push_swap program in a linked list.
 * All the links of the list are malloc() and should be free() once the program
 * exit.
 *
 * @args:
 *		char *line: the line from the input (read by get_next_line).
 * @return:
 *		t_list *: a pointer to the head of the list (called operations).
 */

t_list	*create_list_with_operations(char *line)
{
	t_list	*operations;
	t_list	*tmp;

	operations = NULL;
	tmp = NULL;
	if (line)
	{
		tmp = ft_lstnew(line);// or ft_strdup(*av)??
		ft_lstadd_back(&operations, tmp);
	}
	return (operations);
}
