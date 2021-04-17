/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 02:13:20 by jfreitas          #+#    #+#             */
/*   Updated: 2021/04/16 01:14:31 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * rrr: rra and rrb at the same time.
 */

void	rrr(t_lst **a, t_lst **b, int fd, t_list **operations)
{
//	t_list	*new;
	char	*opts;

	opts = ft_strdup("rrr\n");
	if (fd == 0 || fd == 2)
	{
		if (fd == 2)
			ft_lstadd_back(operations, ft_lstnew(opts));
		//	*operations = create_list_2(opts);

	//	printf("OPERATIONS->CONTENT = %s", (*operations)->content);
	//	free(opts);
		if ((*a)->next && (*b)->next)
		{
			rra(a, 0, NULL);
			rrb(b, 0, NULL);
		}

/// delete
		printf("\n--->>> %s", "rrr\n");
		print_lists(a, b);
		g_count_operations++;
/// delete

	}
//	ft_lstadd_back(operations, new);
	else if (fd == 1)
	{
		ft_putstr_fd(opts, fd);
		free(opts);
		g_count_operations_after++;
	}
//	return ((*operations));
}

/*
 * rra or rrb: reverse rotate -> shift down all elements of stack a by 1.
 * The last element becomes the first one.
 *
 * 1. head is set to point to the second link of the linked list.
 * 2. loop on *new (which starts from second link), and set last to it.
 * 3. setting last's last pointer to NULL.
 * 4. the next link of *new (the 2nd link of the linked list) is now pointing
 *    to the head of *a or *b.
 * 5. the head of the main list *a or *b is now equal to the head of *new.
 */

void	rra(t_lst **a, int fd, t_list **operations)
{
	t_lst	*last;
	t_lst	*new;
	char	*opts;


	opts = ft_strdup("rra\n");
	if (fd == 0 || fd == 2)
	{
		if (fd == 2)
			ft_lstadd_back(operations, ft_lstnew(opts));
		//	*operations = create_list_2(opts);

	//	printf("OPERATIONS->CONTENT = %s", (*operations)->content);
	//	free(opts);
		last = (*a);
		new = (*a)->next;
		while (new->next)
		{
			last = new;
			new = new->next;
		}
		last->next = NULL;
		new->next = (*a);
		(*a) = new;

/// delete
		printf("\n--->>> %s", "rra\n");
		print_lists(a, NULL);
		g_count_operations++;
/// delete

	}
	else if (fd == 1)
	{
		ft_putstr_fd(opts, fd);
		free(opts);
		g_count_operations_after++;
	}
//	return ((*operations));
}

void	rrb(t_lst **b, int fd, t_list **operations)
{
	t_lst	*last;
	t_lst	*new;
	char	*opts;

	opts = ft_strdup("rrb\n");
	if (fd == 0 || fd == 2)
	{
		if (fd == 2)
			ft_lstadd_back(operations, ft_lstnew(opts));
		//	*operations = create_list_2(opts);

	//	printf("OPERATIONS->CONTENT = %s", (*operations)->content);
//		free(opts);
		last = (*b);
		new = (*b)->next;
		while (new->next)
		{
			last = new;
			new = new->next;
		}
		last->next = NULL;
		new->next = (*b);
		(*b) = new;

/// delete
		printf("\n--->>> %s", "rrb\n");
		print_lists(NULL, b);
		g_count_operations++;
/// delete

	}
	else if (fd == 1)
	{
		ft_putstr_fd(opts, fd);
		free(opts);
		g_count_operations_after++;
	}
//	return ((*operations));
}
