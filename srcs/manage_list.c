/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:01:49 by jfreitas          #+#    #+#             */
/*   Updated: 2021/03/23 02:04:31 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list_a(t_list **a)
{
	t_list	*tmp;

	if (!(*a))
		return ;
	while ((*a))
	{
		tmp = *a;
		*a = (*a)->next;
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
 *		t_list *: a pointer to the head of the list (called a).
 */

t_list	*create_list(char **av)
{
	t_list	*a;
	t_list	*a_tmp;
	int		i;

	i = 0;
	a = NULL;
	a_tmp = NULL;
	while (*av != NULL)
	{
		a_tmp = ft_lstnew(*av);// or ft_strdup(*av)??
		ft_lstadd_back(&a, a_tmp);
	//	printf("list = %s\n", a->content);
		av++;
	}

	return (a);
}

