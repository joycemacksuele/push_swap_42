/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 00:08:21 by jfreitas          #+#    #+#             */
/*   Updated: 2021/06/21 20:55:40 by whoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Function used to shorten the midpoint_sort_a_500 cause it was bigger than
 * 25 lines.
 * It returns 0 if the number on the head of the list a is equal to any number
 * inside the chunk variable, but this number can not be any of the 2 numbers
 * inside the two_last_nbs variable.
 * If the head of a is not equal any number from the range of numbers inside the
 * variable chunk, it returns -1.
 */

static int	ft_nbnb(t_lst **a, char **chunk, char **two_last_nbs)
{
	int		i;
	char	*ret_itoa;

	i = 0;
	ret_itoa = ft_itoa((*a)->nb);
	while (chunk[i])
	{
		if (ft_strcmp(ret_itoa, chunk[i]) == 0
			&& (*a)->nb != ft_atoi(two_last_nbs[0])
			&& (*a)->nb != ft_atoi(two_last_nbs[1]))
		{
			free(ret_itoa);
			return (0);
		}
		i++;
	}
	free(ret_itoa);
	return (-1);
}

/*
 * Function used to shorten the midpoint_sort_a_500 cause it was bigger than
 * 25 lines.
 */

static int	do_operation(t_lst **a, t_lst **b, char *opr, int track_of)
{
	if (ft_strcmp(opr, "pb") == 0)
		pb(a, b, 1);
	else if (ft_strcmp(opr, "ra") == 0)
		ra(a, 1);
	else if (ft_strcmp(opr, "rra") == 0)
		rra(a, 1);
	track_of++;
	return (track_of);
}

/*
 * If it's the last chunk, it will deduce 2 from the chunk length in order to
 * have the 2 biggest numbers on the stack a at the end of this sorting.
 */

void	midpoint_sort_a_500(t_lst **a, t_lst **b, int l_chunk, t_dumb d)
{
	t_lst	*end_a;
	int		t_pb;
	int		t_ra_rra;

	end_a = NULL;
	t_pb = 0;
	t_ra_rra = 0;
	while (t_pb < l_chunk)
	{
		while ((*a) && t_pb < l_chunk && ft_nbnb(a, d.chunk, d.pnbs) == 0)
			t_pb = do_operation(a, b, "pb", t_pb);
		if ((*a) && ft_nbnb(a, d.chunk, d.pnbs) == -1)
		{
			end_a = lstlast((*a));
			while (end_a && t_pb < l_chunk
				&& ft_nbnb(&end_a, d.chunk, d.pnbs) == 0)
			{
				t_ra_rra = do_operation(a, b, "rra", t_ra_rra);
				t_pb = do_operation(a, b, "pb", t_pb);
				end_a = lstlast((*a));
			}
			while ((*a) && t_pb < l_chunk && ft_nbnb(a, d.chunk, d.pnbs) == -1)
				t_ra_rra = do_operation(a, b, "ra", t_ra_rra);
		}
	}
}

char	**get_chunk_from_smaller_nb(char **sorted_a, int len_a, int len_chunk_a)
{
	char	**chunk;
	int		i;
	int		j;

	chunk = (char **)malloc(sizeof(char *) * (len_chunk_a + 1));
	if (!chunk)
		return (NULL);
	i = 0;
	j = 0;
	if (len_a < len_chunk_a)
		len_chunk_a = len_a;
	if (len_a < len_chunk_a)
	{
		while (sorted_a[i] && i < len_chunk_a)
			chunk[j++] = ft_strdup(sorted_a[i++]);
		return (chunk);
	}
	while (sorted_a[i] && i < len_chunk_a)
		chunk[j++] = ft_strdup(sorted_a[i++]);
	chunk[j] = NULL;
	return (chunk);
}

void	sort_max_500(t_lst **a, t_lst **b)
{
	char	**saved_a;
	char	**sorted_a;
	int		l_chunk_a;
	t_dumb	dumb;

	l_chunk_a = lstlen(a) / 10;
	dumb.chunk = NULL;
	while ((*a)->next->next)
	{
		saved_a = save_stack_to_array(a, lstlen(a));
		if (saved_a == NULL)
			return ;
		sorted_a = sort_array(&saved_a[0]);
		if (sorted_a == NULL)
			return ;
		dumb.chunk = get_chunk_from_smaller_nb(sorted_a, lstlen(a), l_chunk_a);
		dumb.pnbs[0] = sorted_a[lstlen(a) - 2];
		dumb.pnbs[1] = sorted_a[lstlen(a) - 1];
		if (lstlen(a) <= l_chunk_a + 2)
			l_chunk_a = lstlen(a) - 2;
		midpoint_sort_a_500(a, b, l_chunk_a, dumb);
		ft_freetab(dumb.chunk);
		ft_freetab(saved_a);
	}
}
