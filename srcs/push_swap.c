/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 00:08:21 by jfreitas          #+#    #+#             */
/*   Updated: 2021/04/28 03:31:20 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_bigger_number(t_lst **head, int checker, int bigger1)
{
	t_lst	*tmp;
	int		bigger_index;
	int		i;

	bigger_index = 0;
	i = 1;
	tmp = (*head);
	if (!(*head))
		return (-1);
	while (tmp != NULL)
	{
		if (checker == 0 && (*head)->nb == bigger1)
			(*head) = (*head)->next;
		if (tmp->next && (*head)->nb < tmp->next->nb)
		{
			if (checker == 0 && tmp->next->nb != bigger1)
			{
				(*head) = tmp->next;
				bigger_index = i;
			}
			else if (checker == -1)
			{
				(*head) = tmp->next;
				bigger_index = i;
			}
		}
		tmp = tmp->next;
		i++;
	}
	return (bigger_index);
}

void	before_check_next_2_numbers(t_lst **a, t_lst **b)
{
	if ((*a) && ((*a)->next && (*a)->nb > (*a)->next->nb) &&
		((*b)->next && (*b)->nb < (*b)->next->nb))
		ss(a, b, 1);
	else if ((*a)->nb > (*a)->next->nb)
		sa(a, 1);
	if ((*b) && lst_is_sort((*b), -1) == -1)
	{
		if (!(*b)->next->next)
			sb(b, 1);
	}
	else if ((*b) && lst_is_sort((*b), -1) == 0)
	{
		while ((*b))
			pa(a, b, 1);
	}

//		printf("head of b = %d\n", (*b)->nb);
//		printf("length of b = %d\n", lstlen(b));
}

void	rotate_b(t_lst **b, int i1, int i2)
{
	if (i1 < ((lstlen(b) - 1) - i2))
		rb(b, 1);
	else if (i1 >= ((lstlen(b) - 1) - i2))
		rrb(b, 1);
}

int	 bigger_nb_2(t_lst **b, int bigger1, int *bigger2)
{
	t_lst	*head;
	int		i2;

	i2 = 0;
	head = (*b);
	i2 = search_bigger_number(&head, 0, bigger1);
	*bigger2 = head->nb;
	return (i2);
}

int	bigger_nb(t_lst **b, int *bigger1)
{
	t_lst	*head;
	int		i1;

	i1 = 0;
	head = (*b);
	i1 = search_bigger_number(&head, -1, -1);
	*bigger1 = head->nb;
	return (i1);
}

void	from_b_to_a(t_lst **a, t_lst **b)
{
//	t_lst	*head;
	int		bigger1;
	int		bigger2;
	int		i1;
	int		i2;
	int		track_of_pa;

	while ((*b))
	{
		track_of_pa = 0;
		i1 = bigger_nb(b, &bigger1);
		i2 = bigger_nb_2(b, bigger1, &bigger2);
//// test
/*		printf("\n\n------\n");
		printf("head of a = %d\n", (*a)->nb);
		printf("length of a = %d\n\n", lstlen(a));
		if ((*b)->next)
		{
			printf("bigger1 number = %d\n", bigger1);
			printf("i1 = %d\n\n", i1);
		}
		if ((*b)->next)
		{
			printf("bigger2 number = %d\n", bigger2);
			printf("i2 = %d\n", i2);
		}
		printf("------\n\n");
//// test*/
		while (track_of_pa < 2)
		{
			if (((*b)->nb != bigger1 && (*b)->nb != bigger2) &&
				((*b)->next && ((*b)->next->nb == bigger1 ||
				(*b)->next->nb == bigger2)) && ((i1 <= 2 ||
				i1 > lstlen(b) / 2) && (i2 <= 2 || i2 > lstlen(b) / 2)))
			{
				sb(b, 1);
			//	printf("head of b = %d\n", (*b)->nb);
			//	printf("b->next = %d\n", (*b)->next->nb);
			}
		///	printf("bigger1 number = %d\n", bigger1);
		//	printf("bigger2 number = %d\n", bigger2);
			while ((bigger1 && bigger2 && (*a)) &&
				((*b)->nb != bigger1 && (*b)->nb != bigger2))
				rotate_b(b, i1, i2);
			if ((*b)->nb == bigger1 || (*b)->nb == bigger2)
			{
				track_of_pa++;
				if ((*b)->nb == bigger1)
					i1 = i2;
				else if ((*b)->nb == bigger2)
					i2 = i1;
				pa(a, b, 1);
			}
		//	printf("track_of_pa = %d\n", track_of_pa);
		}
		before_check_next_2_numbers(a, b);
	}
}

void	pick_algo(t_lst **a, t_lst **b, int ac)
{
	if (!(*a))
		return ;
	if (ac == 2 || ac == 3)
		sort_max_3(a);
	else if (ac <= 20)
		sort_max_12(a, b);
	else
	{
		if (ac <= 100)
			sort_max_100(a, b);
		else
			sort_max_500(a, b);
		if (((*a)->next && (*a)->nb > (*a)->next->nb) && ((*b)->next && (*b)->nb < (*b)->next->nb))
			ss(a, b, 1);
		else if ((*a)->next && (*a)->nb > (*a)->next->nb)
			sa(a, 1);
		from_b_to_a(a, b);
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
		//	free_lst(&b);
		}
	}
//	printf("NUMBER OF REGISTERS = %d\n", g_count_operations);
	return (0);
}
