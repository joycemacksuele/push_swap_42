/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 00:08:21 by jfreitas          #+#    #+#             */
/*   Updated: 2021/03/28 18:00:31 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Pour 3 values = normal: 1 or 2 ... max 3 opérations
Pour 5 values = normal 5 to 9 and  max 12
Pour 100 values = barème de 1 à 5
  - moins de 700: 5 this one
  - moins de 900: 4
  - moins de 1100: 3
  - moins de 1300: 2
  - moins de 1500: 1:
Pour 500 values = barème de 1 à 5
  - moins de 5300: 5 this one
  - moins de 7000: 4
  - moins de 8500: 3
  - moins de 10000: 2
  - moins de 11500: 1
*/

void	pick_algo(t_lst **a, t_lst **b, int ac)
{
	(void)b;
	if (ac == 2 || ac == 3)
		sort_max_3(a, 'a');
	else if (ac <= 20)
		sort_max_12(a, b);
	else if (ac <= 100)
		sort_max_100(a, b);
/*	else
		sort_4();*/

///// test
	printf("------------ Sorted list a ------------\n");

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
	}

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
		if (is_sort(av) == -1)
		{
			a = create_lst(&av[1]);
			pick_algo(&a, &b, ac - 1);
		}
		free_lst(&a);
		free_lst(&b);
	}
	printf("NUMBER OF REGISTERS = %d\n", g_count_operations);
	return (0);
}
