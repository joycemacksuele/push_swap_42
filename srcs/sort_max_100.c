/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_100.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 00:08:21 by jfreitas          #+#    #+#             */
/*   Updated: 2021/05/01 00:13:09 by whoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Funtion to shorten the midpoint_sort_a_100 funtion cause it was bigger than
 * 25 lines.
 */

static int	do_pb(t_lst **a, t_lst **b, int track_of_pb)
{
	pb(a, b, 1);
	return (track_of_pb + 1);
}

static void	check_end_of_lst_100(t_lst **a, t_lst **b, int mid_nb,
		int track_of_ra_rra, int track_of_pb) IT'S TOOO BIGGG 
{
	t_lst	*end_a;

	end_a = NULL;
	end_a = lstlast((*a));
	while (end_a->nb < mid_nb)
	{
		rra(a, 1);
		track_of_ra_rra++;
		pb(a, b, 1);
		track_of_pb++;
		end_a = lstlast((*a));
	}
}

/*
 * The algorithm to sort a usign the mid point sorting.
 * It devides a in 2, and sends everything smaller than the middle number to b.
 * to do that, it checks the head of a first, if the number there is not
 * smaller than the middle number, it will check the end of the list to again
 * seach for the middle number, if it's there, it will do a ra to send it to
 * the top of the list, and loop again (now with a wanted number on top of a).
 */

void	midpoint_sort_a_100(t_lst **a, t_lst **b, int mid_nb)
{
	int		len_a;
	int		len;
	int		track_of_pb;
	int		track_of_ra_rra;

	len_a = lstlen(a) / 2;
	len = lstlen(a) / 2;
	track_of_pb = 0;
	track_of_ra_rra = 0;
	while (len--)
	{
		while ((*a)->nb < mid_nb)
			track_of_pb = do_pb(a, b, track_of_pb);
		if ((*a)->nb >= mid_nb)
		{
			check_end_of_lst_100(a, b, mid_nb, track_of_ra_rra, track_of_pb);
			while ((*a)->nb >= mid_nb && track_of_ra_rra < len_a)
			{
				ra(a, 1);
				track_of_ra_rra++;
			}
		}
	}
}

static int	find_mid_nb(char **saved_a_or_b)
{
	int	array_len;

	array_len = 0;
	if (saved_a_or_b)
	{
		while (saved_a_or_b[array_len])
			array_len++;
		array_len = array_len / 2;
	}
	else
		return (-1);
	return (ft_atoi(saved_a_or_b[array_len]));
}

/*
 * It will loop a untill it has only the two biggest numbers on it.
 * It will first get what is in a and sort it to find it's middle number, to
 * then use it so do the mid point sort algorithm (inside the
 * midpoint_sort_a_100 funtion).
 */

void	sort_max_100(t_lst **a, t_lst **b)
{
	char	**saved_a;
	char	**sorted_a;
	int		mid_nb_a;

	while ((*a)->next->next)
	{
		saved_a = save_stack_to_array(a, lstlen(a));
	//	if ((saved_a = save_stack_to_array(a, lstlen(a))) == NULL)
		//	return ;
		sorted_a = sort_array(&saved_a[0]);
	//	if ((sorted_a = sort_array(&saved_a[0])) == NULL)
		//	return ;
		mid_nb_a = find_mid_nb(sorted_a);
	//	if ((mid_nb_a = find_mid_nb(sorted_a)) == -1)
		//	return ;
		midpoint_sort_a_100(a, b, mid_nb_a);
		ft_freetab(saved_a);
	}
}
