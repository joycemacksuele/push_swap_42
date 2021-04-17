/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:01:49 by jfreitas          #+#    #+#             */
/*   Updated: 2021/04/15 02:03:46 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	free_list(void *operations)
{
	//if (!operations)
	//	return ;
//	free(operations->content);// ???? content was allocated??
	free(operations);
	operations = NULL;
}
/*void	free_list(t_list **operations)
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
}*/


t_list	*create_list_2(char *line)
{
	t_list	*operations;
	t_list	*tmp;

	operations = NULL;
	tmp = NULL;
	if (line != NULL)
	{
		tmp = ft_lstnew(line);
		ft_lstadd_back(&operations, tmp);
	}
	return (operations);
}

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

t_list	*create_list(char **line)
{
	t_list	*operations;
	t_list	*tmp;

	operations = NULL;
	tmp = NULL;
	while (*line != NULL)
	{
		tmp = ft_lstnew(*line);
		ft_lstadd_back(&operations, tmp);
		line++;
	}
	return (operations);
}
