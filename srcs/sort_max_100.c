/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_100.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 00:08:21 by jfreitas          #+#    #+#             */
/*   Updated: 2021/04/27 03:01:54 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_end_of_lst_100(t_lst **a, t_lst **b, int mid_nb,
			int track_of_ra_rra, int track_of_pb)
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
	//	ret_chunk_size++;
		end_a = lstlast((*a));
		//end_b = lst_before_last((*b));
	//	printf("track_of_ra_rra = %d\n", track_of_ra_rra);
	}
}


void	midpoint_sort_a_100(t_lst **a, t_lst **b, int mid_nb)
{
//	t_lst	*end_b;
	int		len_a;
	int		len;
//	int		ret_chunk_size;
	int		track_of_pb;
	int		track_of_ra_rra;

	//end_b = NULL;
	len_a = lstlen(a) / 2;
	len = lstlen(a) / 2;
	track_of_pb = 0;
	track_of_ra_rra = 0;
//	ret_chunk_size = 0;
	while (len--)
	{
		while ((*a)->nb < mid_nb)
		{
			pb(a, b, 1);
			track_of_pb++;
		//	ret_chunk_size++;
		}
		if ((*a)->nb >= mid_nb)
		{
			check_end_of_lst_100(a, b, mid_nb, track_of_ra_rra, track_of_pb);
			while ((*a)->nb >= mid_nb && track_of_ra_rra < len_a)
			{
			//	printf("RA LOOP ---\n");
				ra(a, 1);
				track_of_ra_rra++;
			}
		}
	}
//	return (ret_chunk_size);
}

int	find_mid_nb(char **saved_a_or_b)
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

void	sort_max_100(t_lst **a, t_lst **b)
{
	char	**saved_a;
	char	**sorted_a;
	int		mid_nb_a;

	while ((*a)->next->next)
	{
		if ((saved_a = save_stack_to_array(a, lstlen(a))) == NULL)
			return ;

		///test
	/*	int	i = 0;
		while (saved_a[i])
		{
			printf("saved a = %s\n", saved_a[i]);
			i++;
		}
		printf("\n---------------------------------------------------\n\n");
		///test*/

		if ((sorted_a = sort_array(&saved_a[0])) == NULL)
			return ;
		if ((mid_nb_a = find_mid_nb(sorted_a)) == -1)
			return ;

		///test
	/*	int i = 0;
		while (sorted_a[i])
		{
			printf("sorted a = %s\n", sorted_a[i]);
			i++;
		}
	//	printf("\n-> mid_nb_a = %d\n", mid_nb_a);
		printf("\n---------------------------------------------------\n\n");
		///test*/

		midpoint_sort_a_100(a, b, mid_nb_a);

		ft_freetab(saved_a);
		//ft_freetab(sorted_a);
	}
}
