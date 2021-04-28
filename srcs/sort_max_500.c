/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 00:08:21 by jfreitas          #+#    #+#             */
/*   Updated: 2021/04/27 18:02:14 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_nbnb(t_lst **a, char **chunk, char **two_last_nbs)
{
	int		i;
	char	*ret_itoa;

	i = 0;
//	printf("          entered ft_nbnb\n");
	ret_itoa = ft_itoa((*a)->nb);

	//printf("->-> itoa of nb = %s\n", ret_itoa);

	while (chunk[i])
	{
		if (ft_strcmp(ret_itoa, chunk[i]) == 0 &&
			(*a)->nb != ft_atoi(two_last_nbs[0]) &&
			(*a)->nb != ft_atoi(two_last_nbs[1]))
		{
		//	printf("ret = 0\n\n");
			free(ret_itoa);
			return (0);
		}
		i++;
	}
	free(ret_itoa);
//	printf("ret = -1\n\n");
	return (-1);
}

int	do_operation(t_lst **a, t_lst **b, char *opr, int track_of)
{
	if (ft_strcmp(opr, "pb") == 0)
		pb(a, b, 1);
	else if (ft_strcmp(opr, "ra") == 0)
	{
		ra(a, 1);
	//	printf("RA LOOP ---\n");
	}
	else if (ft_strcmp(opr, "rra") == 0)
		rra(a, 1);
	track_of++;
	return (track_of);
}

void	midpoint_sort_a_500(t_lst **a, t_lst **b, char **chunk, int l_chunk, char **pnbs)
{
	t_lst	*end_a;
//	t_lst	*end_b;
//	int		len_a;
	int		t_pb;
	int		t_ra_rra;

	end_a = NULL;
	//end_b = NULL;
	//len_a = lstlen(a);
	t_pb = 0;
	t_ra_rra = 0;
	if (lstlen(a) <= l_chunk + 2)// if its the last chunk
		l_chunk = lstlen(a) - 2;
	while (t_pb < l_chunk)
	{
//		printf("PENULTIMO = %s\n", pnbs[0]);
//		printf("ULTIMO = %s\n", pnbs[1]);
		//printf("\n------------------------ENTERED WJILE LOOP 500 NUMBERS------------------------\n");
//		printf("l_chunk = %d\n", l_chunk);
//		printf("t_pb = %d\n", t_pb);

		while ((*a) && t_pb < l_chunk && ft_nbnb(a, chunk, pnbs) == 0)
		//{
			t_pb = do_operation(a, b, "pb", t_pb);
		//	pb(a, b, 1);
		//	t_pb++;
		//}
		if ((*a) && ft_nbnb(a, chunk, pnbs) == -1)
		{
			end_a = lstlast((*a));
			while (end_a && t_pb < l_chunk && ft_nbnb(&end_a, chunk, pnbs) == 0)
			{
				t_ra_rra = do_operation(a, b, "rra", t_ra_rra);
				//rra(a, 1);
				//t_ra_rra++;
				t_pb = do_operation(a, b, "pb", t_pb);
				//pb(a, b, 1);
				//t_pb++;
				end_a = lstlast((*a));
			//	end_b = lst_before_last((*b));
			//	printf("t_ra_rra = %d\n", t_ra_rra);
			}
			while ((*a) && t_pb < l_chunk && ft_nbnb(a, chunk, pnbs) == -1)
		//	{
				t_ra_rra = do_operation(a, b, "ra", t_ra_rra);
			//	printf("RA LOOP ---\n");
			//	ra(a, 1);
			//	t_ra_rra++;
		//	}
		}
	}
}

char	**get_chunk_from_smaller_nb(char **sorted_a, int len_a, int len_chunk_a)
{
	char	**chunk;
	int		i;
	int		j;

	chunk = (char **)malloc(sizeof(char *) * (len_chunk_a + 1));
	i = 0;
//	i = len_a / 2 - (len_chunk_a / 2);
//	chunk = ft_strdup("");
	j = 0;
	if (len_a < len_chunk_a)
		len_chunk_a = len_a;
	if (len_a < len_chunk_a)
	{
		while (sorted_a[i] && i < len_chunk_a)//len_a)
	//	{
//			chunk = ft_strjoin(chunk, sorted_a[i]);
//			chunk = ft_strjoin(chunk, " ");
			chunk[j++] = ft_strdup(sorted_a[i++]);
	//		i++;
	//		j++;
	//	}
		return (chunk);
	}
	while (sorted_a[i] && i < len_chunk_a)//len_a / 2 + (len_chunk_a / 2))
//	{
//		chunk = ft_strjoin(chunk, sorted_a[i]);
//		chunk = ft_strjoin(chunk, " ");
		chunk[j++] = ft_strdup(sorted_a[i++]);
	//	i++;
	//	j++;
//	}
	chunk[j] = NULL;
	return (chunk);
}

void	sort_max_500(t_lst **a, t_lst **b)
{
	char	**saved_a;
	char	**sorted_a;
	char	**chunk;
	int		len_chunk_a;
	char	*penultimate_nb[2];

	len_chunk_a = lstlen(a) / 10;
	chunk = NULL;
	while ((*a)->next->next)
	{
		if ((saved_a = save_stack_to_array(a, lstlen(a))) == NULL)
			return ;
		if ((sorted_a = sort_array(&saved_a[0])) == NULL)
			return ;

	//	int i = 0;
	//	while (sorted_a[i])
	//		printf("saved_a = %s\n", saved_a[i++]);

		chunk = get_chunk_from_smaller_nb(sorted_a, lstlen(a), len_chunk_a);

	/*	i = 0;
		while (chunk[i])
		{
			printf("chunk = %s\n", chunk[i]);
			i++;
		}*/

		penultimate_nb[0] = sorted_a[lstlen(a) - 2];
		penultimate_nb[1] = sorted_a[lstlen(a) - 1];
		midpoint_sort_a_500(a, b, chunk, len_chunk_a, penultimate_nb);
		ft_freetab(chunk);
		ft_freetab(saved_a);
	}
}
