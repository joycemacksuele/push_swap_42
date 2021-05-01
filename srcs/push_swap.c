/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 00:08:21 by jfreitas          #+#    #+#             */
/*   Updated: 2021/05/01 00:07:11 by whoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Passing all numbers from the stack b to the staack a, by getting the 2
 * biggest numbers on b, checking which one is better to send to a (the one
 * that uses less operations because its closer to the top of b), and sending
 * it with pa.
 * At the end, it checks if those 2 numbers just sent to a need to be sorted
 * with sa (or ss if possible to use less operations at the end).
 */

void	from_b_to_a(t_lst **a, t_lst **b, t_dumb track_of)
{
	int		bigger1;
	int		bigger2;
	int		i1;
	int		i2;

	while ((*b))
	{
		track_of.oprt = 0;
		i1 = bigger_nb(b, &bigger1);
		i2 = bigger_nb_2(b, bigger1, &bigger2);
		while (track_of.oprt < 2 && bigger1 && bigger2)
		{
			if (if1(b, bigger1, bigger2) == 1 && if2(b, i1, i2) == 1)
				sb(b, 1);
			while ((*a) && ((*b)->nb != bigger1 && (*b)->nb != bigger2))
				rotate_b(b, i1, i2);
			if ((*b)->nb == bigger1 || (*b)->nb == bigger2)
			{
				i1 = nbr_equal_bigger1(b, bigger1, i1, i2);
				i2 = nbr_equal_bigger2(b, bigger2, i1, i2);
				track_of.oprt = do_pa(a, b, track_of.oprt);
			}
		}
		before_check_next_2_numbers(a, b);
	}
}

/*
 * Here I devide the sorting in 3 algorithms.
 * For when the numbers input are smaller than 3, or from 3 to 5, or from 5 to
 * 100, or from 100 to 500.
 * At the end of when the numbers input is bigger than 100 and all of it is
 * inside stack b (minus 2 last numbers), it checks if a ss or a sa is needed
 * to sort those 2 last bigger numbers on the stack a.
 *
 * Obs.: the struct t_dumb is used here just because te function from_b_to_a
 * was bigger than 25 lines and I did not find another way to shorten it.
 */

void	pick_algo(t_lst **a, t_lst **b, int ac)
{
	t_dumb	track_of;

	track_of.oprt = 0;
	if (!(*a))
		return ;
	if (ac == 2 || ac == 3)
		sort_max_3(a);
	else if (ac <= 5)
		sort_max_5(a, b);
	else
	{
		if (ac <= 100)
			sort_max_100(a, b);
		else
			sort_max_500(a, b);
		if (((*a)->next && (*a)->nb > (*a)->next->nb)
			&& ((*b)->next && (*b)->nb < (*b)->next->nb))
			ss(a, b, 1);
		else if ((*a)->next && (*a)->nb > (*a)->next->nb)
			sa(a, 1);
		from_b_to_a(a, b, track_of);
	}
}

int	main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;

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
			free_lst(&a);
		}
	}
	return (0);
}
