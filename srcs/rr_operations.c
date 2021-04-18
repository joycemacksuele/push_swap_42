/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 02:13:20 by jfreitas          #+#    #+#             */
/*   Updated: 2021/04/17 22:43:28 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * rr: ra and rb at the same time.
 */

void	rr(t_lst **a, t_lst **b, int fd, t_list **operations)
{
	char	*opts;

	opts = ft_strdup("rr\n");
	if (fd == 0 || fd == 2)
	{
		if (fd == 2)
			ft_lstadd_back(operations, ft_lstnew(opts));
		//	*operations = create_list_2(opts);

//		printf("OPERATIONS->CONTENT = %s", (*operations)->content);
		if ((*a)->next && (*b)->next)
		{
			ra(a, 0, NULL);
			rb(b, 0, NULL);
		}

/// delete
	//	printf("\n--->>> %s", "rr\n");
		print_lists(a, b);
		g_count_operations++;
/// delete

	//	free(opts);
	}
	else if (fd == 1)
	{
		ft_putstr_fd(opts, fd);
		free(opts);
		g_count_operations_after++;
	}
//	return ((*operations));
}

/*
 * ra or rb: rotate -> shift up all elements of stack a by 1. The first
 * element becomes the last one.
 */

void	ra(t_lst **a, int fd, t_list **operations)
{
	int		tmp;
	t_lst	*new;
	char	*opts;

	opts = ft_strdup("ra\n");
	if (fd == 0 || fd == 2)
	{
		if (fd == 2)
			ft_lstadd_back(operations, ft_lstnew(opts));
	//		*operations = create_list_2(opts);

	//	printf("OPERATIONS->CONTENT = %s", (*operations)->content);
	//	free(opts);
		if ((*a))
		{
			tmp = (*a)->nb;// tmp = first nb of list
			(*a) = (*a)->next;// moving head to next list
			new = lstnew(tmp);// creating new list with the first nb on it
			lstadd_back(a, new);//adding this new list to the end of the linked list
		}

/// delete
		//printf("\n--->>> %s", "ra\n");
		print_lists(a, NULL);
		g_count_operations++;
/// delete


	}
	else if (fd == 1)
	{
		ft_putstr_fd(opts, fd);
		free(opts);
		g_count_operations_after++;
	//	free(new);
	}
//	return ((*operations));
}

void	rb(t_lst **b, int fd, t_list **operations)
{
	int		tmp;
	t_lst	*new;
	char	*opts;

	opts = ft_strdup("rb\n");
	if (fd == 0 || fd == 2)
	{
		if (fd == 2)
			ft_lstadd_back(operations, ft_lstnew(opts));
		//	*operations = create_list_2(opts);

	//	printf("OPERATIONS->CONTENT = %s", (*operations)->content);
	//	free(opts);
		if ((*b))
		{
			tmp = (*b)->nb;// tmp = first nb of list
			(*b) = (*b)->next;// moving head to next list
			new = lstnew(tmp);// creating new list with the first nb on it
			lstadd_back(b, new);//adding this new list to the end of the linked lit
		}

/// delete
		//printf("\n--->>> %s", "rb\n");
		print_lists(NULL, b);
		g_count_operations++;
/// delete

	}
	else if (fd == 1)
	{
		ft_putstr_fd(opts, fd);
		free(opts);
		g_count_operations_after++;
	//	free(new);
	}
//	return ((*operations));
}
