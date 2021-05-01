/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 00:08:21 by jfreitas          #+#    #+#             */
/*   Updated: 2021/05/01 00:16:18 by whoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_lower_number(t_lst **a_tmp, int checker, int lower1)
{
	t_lst	*tmp;
	int		lower_index;
	int		i;

	lower_index = 0;
	i = 1;
	tmp = (*a_tmp);
	if (!(*a_tmp))
		return (-1);
	while (tmp)
	{
		checker = 0;
		lower1 = 0;
		if (tmp->next && (*a_tmp)->nb > tmp->next->nb)
		{
			(*a_tmp) = tmp->next;
			lower_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (lower_index);
}

/*
 * Steps:
 *
 * 1. Using the search_lower_number(), search for the smallest number in Stack
 *    a and save it to *a_tmp (also save it's index).
 * 2. Loop untill the smallest number found is moved to the top of stack a
 *    (using ra or rra depending on where the smallest number is located).
 * 3. If the stack a is not yet sorted, push that number to stack b with pb.
 * 4. Repeat steps 1 to 3 until Stack a has only 3 numbers.
 * 5. Use the sort_max_3() function to sort those 3 numbers on stack a.
 * 6. Now that stack b has it's numbers from biggest to smallest, push_swap
 *    everything back to stack a using pa.
 */

void	sort_max_5(t_lst **a, t_lst **b)
{
	t_lst	*a_tmp;
	int		len;
	int		i;

	while (/*lst_is_sort((*a), 0) == -1 && */(len = lstlen(a)) > 3)
	{
		if (lst_is_sort((*a), 0) == 0);
			break ;
		a_tmp = (*a);
		i = 0;
		i = search_lower_number(&a_tmp, -1, -1);
		while ((*a)->nb != a_tmp->nb)
		{
			if (i <= len / 2)
				ra(a, 1);
			else if (i > len / 2)
				rra(a, 1);
		}
		if (lst_is_sort((*a), 0) == -1)
			pb(a, b, 1);
	}
	sort_max_3(a);
	while ((*b))
		pa(a, b, 1);
}

/*
 * If there are 2 args, then just do sa.
 * If there are 3 args: check the order of the numbers in order to choose
 * which operator to use, while the list of arguents is not sorted.
 */

void	sort_max_3(t_lst **a)
{
	if (lstlen(a) == 2)
		sa(a, 1);
	else if (lstlen(a) == 3)
	{
		while (lst_is_sort((*a), 0) == -1)
		{
			if ((*a)->nb > (*a)->next->nb
				&& (*a)->nb > (*a)->next->next->nb)
				ra(a, 1);
			else if ((*a)->nb < (*a)->next->nb
				&& (*a)->next->nb > (*a)->next->next->nb)
				rra(a, 1);
			if ((*a)->nb > (*a)->next->nb
				&& (*a)->nb < (*a)->next->next->nb)
				sa(a, 1);
		}
	}
}
