/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 00:08:21 by jfreitas          #+#    #+#             */
/*   Updated: 2021/04/05 01:12:20 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pick_algo(t_lst **a, t_lst **b, int ac)
{
	if (ac == 2 || ac == 3)
		sort_max_3(a, 'a');
	else if (ac <= 20)
		sort_max_12(a, b);
	else
		sort_max_100(a, b);
//	else
//		sort_max_500(a, b);
	//	sort_max_500(a, b);

///// test
/*	printf("------------ Sorted list a ------------\n");

	printf("len a = %d\n", lstlen(a));
	if ((*a))
		printf("a\n-\n");
	while (*a)
	{
		printf("%d\n", (int)(*a)->nb);
		(*a) = (*a)->next;
	}

	printf("------------ Sorted list b ------------\n");

	printf("len b = %d\n", lstlen(b));
	if (!(*b))
		printf("List b is empty\n");
	else
		printf("b\n-\n");
	while (*b)
	{
		printf("%d\n", (int)(*b)->nb);
		(*b) = (*b)->next;
	}*/

///// test
}

int	main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;

	g_count_operations = 0;
	a = NULL;
	b = NULL;
	if (handle_wrong_ac(ac) == -1)
		return (-1);
	else if (ac >= 2)
	{
		if (not_int(av) == -1 || find_doubles(av) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		if (is_sort(av, -1) == -1)
		{
			a = create_lst(&av[1]);
			pick_algo(&a, &b, ac - 1);
		}
		free_lst(&a);
		free_lst(&b);
	}
//	printf("NUMBER OF REGISTERS = %d\n", g_count_operations);
	return (0);
}
