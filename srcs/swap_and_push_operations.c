/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 02:13:20 by jfreitas          #+#    #+#             */
/*   Updated: 2021/04/17 03:51:18 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lists(t_lst **a, t_lst **b)
{
	t_lst *tmp;
	t_lst *btmp;
	int		i;

	if (a)
		tmp = (*a);
	else
		tmp = NULL;
	if (b)
		btmp = (*b);
	else
		btmp = NULL;
	i = 1;
	while (tmp)
	{
	//	while (i-- >= 0)
	//	{
			printf("a = %d		", tmp->nb);
			if (!btmp)
				printf("\n");
	//	}
		if (btmp)
		{
			printf("		b = %d\n", btmp->nb);
			btmp = btmp->next;
		}
		tmp = tmp->next;
	}
	while (btmp)
	{
		printf("					b = %d\n", btmp->nb);
		btmp = btmp->next;
	}

	printf("\n---------------------------------------------------\n");
}

/*
 * sa or sb: swap -> swap the first 2 elements at the top of stack.
 * Do nothing if there is only one or no elements).
 */

void	sa(t_lst **a, int fd, t_list **operations)
{
	int		tmp;
	char	*opts;

	opts = ft_strdup("sa\n");
	if (fd == 0 || fd == 2)
	{
		if (fd == 2)
		{
			ft_lstadd_back(operations, ft_lstnew(opts));
/// delete
			printf("\n--->>> %s", "sa\n");
			print_lists(a, 0);
			g_count_operations++;
/// delete
		}

		//	*operations = create_list_2(opts);

//		printf("OPERATIONS->CONTENT = %s", (*operations)->content);
	//	free(opts);
		if ((*a))
		{
			tmp = (*a)->nb;
			(*a)->nb = (*a)->next->nb;
			(*a)->next->nb = tmp;
		}
	}
	else if (fd == 1)
	{
		ft_putstr_fd(opts, fd);
		free(opts);
		g_count_operations_after++;
	}
//	return ((*operations));
}

void	sb(t_lst **b, int fd, t_list **operations)
{
	int		tmp;
	char	*opts;

	opts = ft_strdup("sb\n");
	if (fd == 0 || fd == 2)
	{
		if (fd == 2)
		{
			ft_lstadd_back(operations, ft_lstnew(opts));
/// delete
			printf("\n--->>> %s", "sb\n");
			print_lists(0, b);
			g_count_operations++;
/// delete
		}
		//	*operations = create_list_2(opts);

	//	printf("OPERATIONS->CONTENT = %s", (*operations)->content);
	//	free(opts);
		if ((*b))
		{
			tmp = (*b)->nb;
			(*b)->nb = (*b)->next->nb;
			(*b)->next->nb = tmp;
		}



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
 * ss: sa and sb at the same time.
 */

void	ss(t_lst **a, t_lst **b, int fd, t_list **operations)
{
	char	*opts;

	opts = ft_strdup("ss\n");
	if (fd == 0 || fd == 2)
	{
		if (fd == 2)
			ft_lstadd_back(operations, ft_lstnew(opts));
		//	*operations = create_list_2(opts);

	//	printf("OPERATIONS->CONTENT = %s", (*operations)->content);
	//	free(opts);
		if ((*a)->next && (*b)->next)
		{
			sa(a, 0, NULL);
			sb(b, 0, NULL);
		}

/// delete
		printf("\n--->>> %s", "ss\n");
		print_lists(a, b);
		g_count_operations++;
/// delete

	}

	else if (fd == 1)
	{
		ft_putstr_fd("ss\n", fd);
		free(opts);
		g_count_operations_after++;
	}
//	return ((*operations));
}

/*
 * pb: push a -> take the first element at the top of a and put it at the top
 *  of b. Do nothing if the other stack is empty.
 */

void	pb(t_lst **a, t_lst **b, int fd, t_list **operations)
{
	t_lst	*tmp;
	int		nb;
	char	*opts;

	opts = ft_strdup("pb\n");
	tmp = NULL;
	nb = 0;
	if (fd == 0 || fd == 2)
	{
		if (fd == 2)
			ft_lstadd_back(operations, ft_lstnew(opts));
		//	*operations = create_list_2(opts);
	//	printf("OPERATIONS->CONTENT = %s", (*operations)->content);
	//	free(opts);
		if (a && *a)
		{
			nb = (*a)->nb;
			tmp = lstnew(nb);
			lstadd_front(b, tmp);
			if ((*a)->next)
				(*a) = (*a)->next;
			else
				free_lst(a);

	//	free(tmp);
		//	(*a) = NULL;
		}

/// delete
		printf("\n--->>> %s", "pb\n");
		print_lists(a, b);
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

/*
 * pa: push a -> take the first element at the top of b and put it at the top
 *  of a. Do nothing if the other stack is empty.
 */

void	pa(t_lst **a, t_lst **b, int fd, t_list **operations)
{
	t_lst	*tmp;
	int		nb;
	char	*opts;

	opts = ft_strdup("pa\n");
	tmp = NULL;
	nb = 0;
	if (fd == 0 || fd == 2)
	{
		if (fd == 2)
			ft_lstadd_back(operations, ft_lstnew(opts));
		//	*operations = create_list_2(opts);

	//	printf("OPERATIONS->CONTENT = %s", (*operations)->content);
	//	free(opts);
		if (b && *b)
		{
			nb = (*b)->nb;
			tmp = lstnew(nb);
			lstadd_front(a, tmp);
			if ((*b)->next)
				(*b) = (*b)->next;
			else
				free_lst(b);
	/*	//test ------------------
		while ((*a))
		{
			printf("a = %d\n", (*a)->nb);
			(*a) = (*a)->next;
		}
		printf("\n\n");
		while ((*b))
		{
			printf("b = %d\n", (*b)->nb);
			(*b) = (*b)->next;
		}
		//test ------------------*/
		}

/// delete
		printf("\n--->>> %s", "pa\n");
		print_lists(a, b);
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
