/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 00:08:21 by jfreitas          #+#    #+#             */
/*   Updated: 2021/04/01 02:05:32 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	sort_b(t_lst **b)
{
	t_lst	*tmp;
	t_lst	*lower;

	tmp = (*b);
	lower = (*b);
	search_lower_number(&lower, -1, -1);
	while (b && lst_is_sort((*b), -1) == -1)
	{
		printf("ENTERED SORT B\n");
		if (tmp->next && tmp->nb < tmp->next->nb && tmp->nb != lower->nb)
			sa_sb(b, 'b', 1);
		else if (tmp->next && tmp->nb > tmp->next->nb)
		{
			ra_rb(b, 'b', 1);
			tmp = tmp->next;
		}
		if ((*b)->nb == lower->nb)
			ra_rb(b, 'b', 1);
	}
}*/

/*void	chunks(t_lst **a, t_lst **b, int chunck_end)
{
	t_lst	*head;
	t_lst	*lower1;
	t_lst	*lower2;
	int		i1;
	int		i2;

	while (1)
	{
		if (lstlen(b) >= chunck_end || !(*a))
			break ;
		head = (*a);
		i1 = 0;
		i1 = search_lower_number(&head, -1, -1);
		lower1 = head;
		head = (*a);
		i2 = 0;
		i2 = search_lower_number(&head, 1, lower1->nb);
		lower2 = head;

//// test
		printf("\n\n------\n");
		printf("head of a = %d\n", (*a)->nb);
		printf("length of a = %d\n\n", lstlen(a));
		if ((*a)->next)
		{
			printf("lower1 number = %d\n", lower1->nb);
			printf("i1 = %d\n\n", i1);
		}
		if ((*a)->next)
		{
			printf("lower2 number = %d\n", lower2->nb);
			printf("i2 = %d\n", i2);
		}
		printf("------\n\n");
//// test

		while ((lower1 && lower2 && (*a)) &&
			((*a)->nb != lower1->nb && (*a)->nb != lower2->nb))
		{
			if (i1 < ((lstlen(a) - 1) - i2))
				ra_rb(a, 'a', 1);
			else if (i1 >= ((lstlen(a) - 1) - i2))
				rra_rrb(a, 'a', 1);
		}
		if (lst_is_sort((*a), 0) == -1)
		{
			if (!(*a)->next->next)
				sa_sb(a, 'a', 1);
			pb(a, b, 1);
		}
		else if (lst_is_sort((*a), 0) == 0 && lstlen(b) < chunck_end)
			pb(a, b, 1);
	//	printf("head of b = %d\n", (*b)->nb);
	//	printf("length of b = %d\n", lstlen(b));
	}
}*/

void	sort_max_500(t_lst **a, t_lst **b)
{
	int	chunk;
	int	chunck_end;

	chunk = 0;
	chunck_end = 20;
	while (chunk <= 25)
	{
		if ((*a))
			chunks(a, b, chunck_end);
		sort_b(b);
		if (lstlen(a) >= 1)
			chunck_end = chunck_end + 20;
		chunk++;
	}
	while ((*b))
		pa(a, b, 1);
}
