/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 00:08:21 by jfreitas          #+#    #+#             */
/*   Updated: 2021/03/23 23:59:13 by jfreitas         ###   ########.fr       */
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
	if (ac == 3)
		sort_1(a, b);
/*	else if (ac <= 5)
		sort_2();
	else if (ac <= 100)
		sort_3();
	else if (ac <= 500)
		sort_4();
	else
		sort_5();*/
}

/*
 * Looping av to check if the numbers of the arguments are sorted or not.
 * Obs.: atoi can be used because if has already passed the error functions,
 * so if itgot here, it means that the arguments are indeed not duplicated
 * signed intergers.
 *
 * @args:
 *		char **av: the arguments of the program call.
 * @return:
 *		int: 0 is it's sorted and -1 if it's not sorted.
 */

int	is_sort(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (av[i + 1] && ft_atoi(av[i]) > ft_atoi(av[i + 1]))
			return (-1);
		i++;
	}
	ft_putstr_fd("Numbers are already sorted!\n", 2);
	return (0);
}

int	main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;

	a = NULL;
	b = NULL;
	if (ac <= 1)
	{
		ft_putstr_fd("Signed integer argument needed!\n", 2);
		return (-1);
	}
	else if (ac >= 2)
	{
		if (not_int(av) == -1 || find_doubles(av) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		if (is_sort(av) == -1)
		{
			a = create_list(&av[1]);
			pick_algo(&a, &b, ac - 1);
		}
/*		while (a != NULL)
		{
			printf("%d\n", a->nb);
			a = a->next;
		}*/
		if (a)
			free_list_a(&a);
	}
	return (0);
}
