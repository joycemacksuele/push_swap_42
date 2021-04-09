/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_100.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 00:08:21 by jfreitas          #+#    #+#             */
/*   Updated: 2021/04/09 02:01:19 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	search_bigger_number(t_lst **bigger)//MAYBE DELETE
{
	t_lst	*tmp;
	int		bigger_index;
	int		i;

	bigger_index = 0;
	i = 1;
	tmp = (*bigger);
	if (!(*bigger))
		return (-1);
	while (tmp)
	{
		if (tmp->next && (*bigger)->nb < tmp->next->nb)
		{
			(*bigger) = tmp->next;
			bigger_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (bigger_index);
}*/

void	sort_b(t_lst **b)
{
	t_lst	*tmp;
	t_lst	*lower;

	tmp = (*b);
	lower = (*b);
	search_lower_number(&lower, -1, -1);
	while (b && lst_is_sort((*b), -1) == -1)
	{
		//printf("ENTERED SORT B\n");
		if (tmp->next && tmp->nb < tmp->next->nb && tmp->nb != lower->nb)
			sa_sb(b, 'b', 1);
		else if (tmp->next && tmp->nb > tmp->next->nb)
		{
			ra_rb(b, 'b', 1);
			tmp = tmp->next;
		}
		if ((*b)->nb == lower->nb)
			ra_rb(b, 'b', 1);
	}
}

void	chunks(t_lst **a, t_lst **b, int chunck_end)
{
	t_lst	*head;
	t_lst	*lower1;
	t_lst	*lower2;
	int		i1;
	int		i2;

	while (1)
	{
		if (lstlen(b) >= chunck_end || !(*a))
			break ;
		head = (*a);
		i1 = 0;
		i1 = search_lower_number(&head, -1, -1);
		lower1 = head;
		head = (*a);
		i2 = 0;
		i2 = search_lower_number(&head, 1, lower1->nb);
		lower2 = head;

//// test
	/*	printf("\n\n------\n");
		printf("head of a = %d\n", (*a)->nb);
		printf("length of a = %d\n\n", lstlen(a));
		if ((*a)->next)
		{
			printf("lower1 number = %d\n", lower1->nb);
			printf("i1 = %d\n\n", i1);
		}
		if ((*a)->next)
		{
			printf("lower2 number = %d\n", lower2->nb);
			printf("i2 = %d\n", i2);
		}
		printf("------\n\n");
//// test*/

		while ((lower1 && lower2 && (*a)) &&
			((*a)->nb != lower1->nb && (*a)->nb != lower2->nb))
		{
			if (i1 < ((lstlen(a) - 1) - i2))
				ra_rb(a, 'a', 1);
			else if (i1 >= ((lstlen(a) - 1) - i2))
				rra_rrb(a, 'a', 1);
		}
		if (lst_is_sort((*a), 0) == -1)
		{
			if (!(*a)->next->next)
				sa_sb(a, 'a', 1);
			if (((*a) && (*a)->next && (*a)->nb < (*a)->next->nb) && ((*b) && (*b)->next && (*b)->nb < (*b)->next->nb))
				ss(a, b, 1);
	//		else if ((*a)->nb < lstlast((*a)) && (*b)->nb < (*b)->next->nb)
			pb(a, b, 1);
		}
		else if (lst_is_sort((*a), 0) == 0 && lstlen(b) < chunck_end)
			pb(a, b, 1);
	//	printf("head of b = %d\n", (*b)->nb);
	//	printf("length of b = %d\n", lstlen(b));
	}
}

/*void	sort_max_100(t_lst **a, t_lst **b)
{
	int	chunk;
	int	chunck_end;

	chunk = 0;
	chunck_end = 20;
	while (chunk <= 5)
	{
		if ((*a))
			chunks(a, b, chunck_end);
		sort_b(b);
		if (lstlen(a) >= 1)
		{
			chunck_end = chunck_end + 20;
		}
		chunk++;
	}
	while ((*b))
		pa(a, b, 1);
}*/
int	chunk_is_sort(t_lst *b, int ascending, int chunk_size)
{
	if (ascending == 0 && b->next)
	{
		while (b && chunk_size--)
		{
			if (b->next && b->nb > b->next->nb)
				return (-1);
			b = b->next;
		}
	}
	else if (ascending == -1 && b->next)
	{
		while (b && chunk_size--)
		{
			if (b->next && b->nb < b->next->nb)
				return (-1);
			b = b->next;
		}
	}
	return (0);
}

int	midpoint_sort_a_from_b_2(t_lst **a, t_lst **b, int mid_nb, int chunk_size)
{
	int	ret_chunk_size;
	int	track_of_ra;
	int	track_of_pb;
	int	chunk_len;
//	int	i;

	ret_chunk_size = 0;
	track_of_ra = 0;
	track_of_pb = 0;
//	i = 0;
	chunk_len = chunk_size;

		//// test
/*				printf("\n++++++++++++++++++++++++++++++++++++++++++++++++\n");
				t_lst *tmp;
				tmp = (*a);
				while (tmp)
				{
					printf("a = %d\n", tmp->nb);
					tmp = tmp->next;
				}
				printf("\n++++++++++++++++++++++++++++++++++++++++++++++++\n");
		///test*/

	while (chunk_len)
	{
		while ((*a)->nb <= mid_nb && track_of_pb <= chunk_size / 2)
		{
			pb(a, b, 1);
			track_of_pb++;
			chunk_len--;
			ret_chunk_size++;
//			printf("track_of_pb = %d\n", track_of_pb);
		}
		if ((*a)->nb > mid_nb && chunk_len >= 1)
		{
			ra_rb(a, 'a', 1);
			track_of_ra++;
//			printf("track_of_RA = %d AND CHUNK LEN = %d\n", track_of_ra, chunk_len);
			chunk_len--;
		}
		//chunk_len--;// melhor aqui???
	}
	while (track_of_ra--)
		rra_rrb(a, 'a', 1);

//	if ((*a)->next && (*a)->nb > (*a)->next->nb)
//		sa_sb(a, 'a', 1);

		//// test
/*				printf("\n++++++++++++++++++++++++++++++++++++++++++++++++\n");
			//	t_lst *tmp;
				t_lst *btmp;
				btmp = (*b);
				tmp = (*a);
				while (tmp)
				{
					printf("a = %d		", tmp->nb);
					tmp = tmp->next;
					if (btmp)
					{
						printf("		b = %d\n", btmp->nb);
						btmp = btmp->next;
					}
				}
				while (btmp)
				{
					printf("				b = %d\n", btmp->nb);
					btmp = btmp->next;
				}

				printf("\n++++++++++++++++++++++++++++++++++++++++++++++++\n");
		///test*/

	return (ret_chunk_size);
}


int	midpoint_sort_a(t_lst **a, t_lst **b, int mid_nb, int chunk_len)
{
	t_lst	*end;
	int		len_a;
	int		len;
	int		ret_chunk_size;

	end = NULL;;
	len_a = lstlen(a);
	if (chunk_len > 0)
		len = chunk_len;
	else
		len = lstlen(a) / 2;
	ret_chunk_size = 0;
	while (len--)
	{
		while ((*a)->nb < mid_nb)
		{
		//	printf("current nb < 12 = %d\n", (*a)->nb);
			pb(a, b, 1);
			ret_chunk_size++;
		}
		if ((*a)->nb >= mid_nb)
		{
			end = lstlast((*a));
			while (end->nb < mid_nb)
			{
				rra_rrb(a, 'a', 1);
				pb(a, b, 1);
				ret_chunk_size++;
				end = lstlast((*a));
			}
			while ((*a)->nb >= mid_nb)
			{
				ra_rb(a, 'a', 1);
				if (lstlen(b) >= chunk_len + len_a / 2)//wrong here
					break ;
			}
		}
	}
	return (ret_chunk_size);
}

char	**sort_array(char **a_or_b)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (a_or_b)
	{
		while (is_sort(&a_or_b[0], 0) == -1)
		{
			i = 0;
			while (a_or_b[i] != NULL)
			{
				if (a_or_b[i + 1] && ft_atoi(a_or_b[i]) > ft_atoi(a_or_b[i+1]))
				{
					tmp = a_or_b[i];
					a_or_b[i] = a_or_b[i + 1];
					a_or_b[i + 1] = tmp;
				}
				if (is_sort(&a_or_b[0], 0) == 0)
					return (a_or_b);
				i++;
			}
		}
	}
	else
		return (NULL);
	return (a_or_b);
}

int	find_mid_nb(char **saved_a_or_b)
{
	int	array_len;
//	int	mid_nb;

	array_len = 0;
	//mid_nb = 0;
	if (saved_a_or_b)
	{
		while (saved_a_or_b[array_len])
			array_len++;
		array_len = array_len / 2;
	//	mid_nb = ft_atoi(saved_a_or_b[array_len]);
	}
	else
		return (-1);
	return (ft_atoi(saved_a_or_b[array_len]));
}

char	**save_stack_to_array(t_lst **a_or_b, int len)
{
	char	**saved;
	char	*itoa;
	t_lst	*tmp;
	int		i;

	saved = (char **)malloc(sizeof(char *) * (len + 1));//(lstlen(a_or_b) + 1));
	itoa = NULL;
	tmp = (*a_or_b);
	i = 0;
//	saved[lstlen(a_or_b)] = NULL;
	if (a_or_b)
	{
		while (tmp && len--)
		{
			itoa = ft_itoa(tmp->nb);
			saved[i] = ft_strdup(itoa);
			free(itoa);
			i++;
			tmp = tmp->next;
		}
		saved[i] = NULL;
		//free(tmp);
	}
	else
		return (NULL);
	return (saved);
}

int	midpoint_sort_a_from_b_1(t_lst **a, t_lst **b, int chunk_size)
{
	char	**saved_a;
	char	**sorted_a;
	int		mid_nb_a;
//	int		chunk_size_tmp;

	if (!(*a))
		return (-1);
	saved_a = NULL;
	sorted_a = NULL;
	if ((saved_a = save_stack_to_array(a, chunk_size)) == NULL)
		return (-1);
/// test
/*		printf("\n---------------------------------------------------\n\n");
		int i = 0;
		while (saved_a[i])
		{
			printf("sorted a = %s\n", saved_a[i]);
			i++;
		}
		printf("\n---------------------------------------------------\n\n");
/// test*/
	
	if ((sorted_a = sort_array(&saved_a[0])) == NULL)
		return (-1);


/// test
/*		printf("\n---------------------------------------------------\n\n");
		i = 0;
		while (sorted_a[i])
		{
			printf("sorted a = %s\n", sorted_a[i]);
			i++;
		}
		printf("\n---------------------------------------------------\n\n");
/// test*/

	if ((mid_nb_a = find_mid_nb(sorted_a)) == -1)
		return (-1);

//	printf("MID_NB_A = %d\n", mid_nb_a);
	chunk_size = midpoint_sort_a_from_b_2(a, b, mid_nb_a, chunk_size);
	//ft_freetab(saved_a);
	ft_freetab(sorted_a);

//	if ((*a)->next && (*a)->nb > (*a)->next->nb)//leave it here or inside midpoint_sort_a_from_b_2????
//		sa_sb(a, 'a', 1);

//	printf("CHUNK SIZE after sort a from b= %d\n", chunk_size);
	return (chunk_size);
}


int	midpoint_sort_b_last(t_lst **a, t_lst **b, int mid_nb_b, int chunk_size)
{
	int	len;
	int	track_of_rb;
	int	track_of_pa;
	int	ret_sorting;

	track_of_rb = 0;
	track_of_pa = 0;
	ret_sorting = 0;
	if (lstlen(b) % 2 == 0)
		len = lstlen(b) / 2;
	else
		len = lstlen(b) / 2 + 1;
	while (chunk_size > 0)
	{
		if (chunk_size == 2 && track_of_rb == 0)
		{
			if ((*b)->next && (*b)->nb < (*b)->next->nb)
			{
//				printf("nb = %d ", (*b)->nb);
				sa_sb(b, 'b', 1);
//				printf("SB and chunk_size == 2\n");
			}
			while ((*b) && chunk_size > 0)
			{
//				printf("nb = %d ", (*b)->nb);
				pa(a, b, 1);
				chunk_size--;
//				printf("PA and chunk_size == 2\n");
			}
		}
		else
		{
			while ((*b)->nb > mid_nb_b && chunk_size != 0)
			{
				if ((*b)->next && (*b)->nb < (*b)->next->nb && chunk_size >= 2)
				{
//					printf("nb = %d ", (*b)->nb);
					sa_sb(b, 'b', 1);
//					printf("SB\n");
				}
//				printf("nb = %d PA\n", (*b)->nb);
				pa(a, b, 1);
				chunk_size--;
				track_of_pa++;

//				printf("|track_of_pa = %d and chunk_size = %d|\n", track_of_pa, chunk_size);
			//	if ((*a)->next && (*a)->nb > (*a)->next->nb)
//	not		//	{
//necessary	//		printf("nb = %d ", (*b)->nb);
			//		sa_sb(a, 'a', 1);
			//		printf("SA\n");
			//	}
			}
			while (chunk_size && (*b)->nb <= mid_nb_b)// && chunk_size > len)
			{
//				printf("nb = %d ", (*b)->nb);
				ra_rb(b, 'b', 1);
				chunk_size--;
				track_of_rb++;
//				printf("|track_of_rb = %d and chunk_size = %d|\n", track_of_rb, chunk_size);
			}
		}
		if (track_of_rb > 0 && chunk_size == 0)
		{
			while (track_of_rb--)
				chunk_size++;
//			printf("|track_of_pa = %d and chunk_size = %d|\n", track_of_pa, chunk_size);
			if (track_of_pa >= 3 && chunk_is_sort((*a), 0, track_of_pa) == -1)
			{
				while (track_of_pa > 2)
				{

//					printf("ENTERED SORTING A AGAIN -> ");
					ret_sorting = midpoint_sort_a_from_b_1(a, b, track_of_pa);
					track_of_pa = track_of_pa - ret_sorting;
					chunk_size = chunk_size + ret_sorting;
//					printf("after sorting a again -> |TRACK PA = %d and CHUNK SIZE = %d|\n", track_of_pa, chunk_size);
				}
				if ((*a)->next && (*a)->nb > (*a)->next->nb)//leave it here or inside midpoint_sort_a_from_b_2????
					sa_sb(a, 'a', 1);
			}
			if (chunk_size > 0)
				return (chunk_size);
		}
	}
	return (0);
}

int	midpoint_sort_b(t_lst **a, t_lst **b, int mid_nb_b, int chunk_size)
{
	int	track_of_rb;
	int	track_of_pa;
	int	ret_sorting;
	int	chunk_size_tmp;

	track_of_rb = 0;
	track_of_pa = 0;
	ret_sorting = 0;
	chunk_size_tmp = chunk_size;
	while (chunk_size >= 0)
	{
		if (chunk_size == 2 && track_of_rb == 0)
		{
			if ((*b)->next && (*b)->nb < (*b)->next->nb)
			{
//				printf("nb = %d ", (*b)->nb);
				sa_sb(b, 'b', 1);
//				printf("SB and chunk_size == 2\n");
			}
			while ((*b) && chunk_size > 0)
			{
//				printf("nb = %d ", (*b)->nb);
				pa(a, b, 1);
				chunk_size--;
//				printf("PA and chunk_size == 2\n");
			}
		}
		else
		{
			while ((*b)->nb > mid_nb_b && chunk_size != 0)
			{
				if ((*b)->next && (*b)->nb < (*b)->next->nb && chunk_size >= 2)
				{
//					printf("nb = %d ", (*b)->nb);
					sa_sb(b, 'b', 1);
//					printf("SB\n");
				}
//				printf("nb = %d PA\n", (*b)->nb);
				pa(a, b, 1);
				chunk_size--;
				track_of_pa++;
			//	if ((*a)->next && (*a)->nb > (*a)->next->nb)
//not		//	{
//necessary	//		printf("nb = %d ", (*b)->nb);
			//		sa_sb(a, 'a', 1);
			//		printf("SA\n");
			//	}
//				printf("|track_of_pa = %d and chunk_size = %d|\n", track_of_pa, chunk_size);
			}
			while (chunk_size && (*b)->nb <= mid_nb_b)// && track_of_rb < chunk_size_tmp)
			{
//				printf("nb = %d ", (*b)->nb);
				ra_rb(b, 'b', 1);
				track_of_rb++;
				chunk_size--;
//				printf("|track_of_rb = %d and chunk_size = %d|\n", track_of_rb, chunk_size);
			}
		}
		if (track_of_rb > 0 && chunk_size == 0)
		{
			while (track_of_rb)
			{
//				printf("nb = %d ", (*b)->nb);
				rra_rrb(b, 'b', 1);
//				printf("RRB\n");
				chunk_size++;
				track_of_rb--;
			}
//			printf("|track_of_pa = %d and chunk_size = %d|\n", track_of_pa, chunk_size);
			if (track_of_pa >= 3 && chunk_is_sort((*a), 0, track_of_pa) == -1)
			{

				while (track_of_pa > 2)
				{

//					printf("ENTERED SORTING A AGAIN -> ");
					ret_sorting = midpoint_sort_a_from_b_1(a, b, track_of_pa);
					track_of_pa = track_of_pa - ret_sorting;
					chunk_size = chunk_size + ret_sorting;
//					printf("after sorting a again -> |TRACK PA = %d and CHUNK SIZE = %d|\n", track_of_pa, chunk_size);
				}
				if ((*a)->next && (*a)->nb > (*a)->next->nb)//leave it here or inside midpoint_sort_a_from_b_2????
					sa_sb(a, 'a', 1);

			}
			//printf("NEW CHUNK SIZE = %d\n", chunk_size);
			if (chunk_size > 0)
				return (chunk_size);// return here and add chunks-nb with chunk_size into the list or deal with this new chunk here cause it heas to check if it has 1, 2 or more than 3 numbers(midpoint sorting) over again.
		//	while (chunk_size > 0)
		//	{
		//		pa(a, b, 1);
		//		chunk_size--;
		//	}
		}
	}
	return (0);
}


void	sort_max_100(t_lst **a, t_lst **b)
{
	char	**saved_a;
	char	**sorted_a;
	t_lst	*chunks;
	int		mid_nb_a;

	chunks = NULL;
	int		chunk_len;
	if (!(*a))
		return ;
	chunk_len = 0;
	while ((*a)->next->next)
	{
		if ((saved_a = save_stack_to_array(a, lstlen(a))) == NULL)
			return ;

		///test
/*		int	i = 0;
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
/*		i = 0;
		while (sorted_a[i])
		{
			printf("sorted a = %s\n", sorted_a[i]);
			i++;
		}
		printf("\n-> mid_nb_a = %d\n", mid_nb_a);
		printf("\n---------------------------------------------------\n\n");
		///test*/

	//	printf("LENGTH B = %d\n", lstlen(b));
		if (lstlen(b) == 0)
		{
			chunk_len = 0;
		//	printf("CHUNK_LEN = %d\n", chunk_len);
		}
		else if (chunks && chunks->nb != 0)
		{
			chunk_len = chunks->nb;
		//	printf("CHUNK_LEN = %d\n", chunk_len);
		}

		midpoint_sort_a(a, b, mid_nb_a, chunk_len);
		lstadd_front(&chunks, lstnew(lstlen(b)));// to know the size of the chunks of b

	///test
	/*	t_lst *tmp;
		t_lst *btmp;
		tmp = (*a);
		btmp = (*b);
		while (tmp)
		{
			printf("a = %d		", tmp->nb);
			tmp = tmp->next;
			if (btmp)
			{
				printf("		b = %d\n", btmp->nb);
				btmp = btmp->next;
			}
		}
		while (btmp)
		{
			printf("				b = %d\n", btmp->nb);
			btmp = btmp->next;
		}
		printf("\n---------------------------------------------------\n");
	///test*/


		ft_freetab(sorted_a);
	//	ft_freetab(saved_a);
	}
	if ((*a)->next && (*a)->nb > (*a)->next->nb)
		sa_sb(a, 'a', 1);


//// test
	/*	t_lst *tmp;
		t_lst *btmp;
		tmp = (*a);
		btmp = (*b);
		while (tmp)
		{
			printf("a = %d		", tmp->nb);
			tmp = tmp->next;
			if (btmp)
			{
				printf("		b = %d\n", btmp->nb);
				btmp = btmp->next;
			}
		}
		while (btmp)
		{
			printf("				b = %d\n", btmp->nb);
			btmp = btmp->next;
		}
		printf("\n---------------------------------------------------\n");
///test*/
/*		while (chunks)
		{
			printf("\n ------> b chunks size = %d\n", chunks->nb);
			chunks = chunks->next;
		}*/
///test

/////////////// SORT B //////////////////////

	char	**saved_b;
	char	**sorted_b;
	int		mid_nb_b;
	int		chunk_size;
	int		new_chunk_size;
	int		ret;

	new_chunk_size = 0;
	ret = 0;
	while ((*b))
	{
		while (chunks)
		{
			if (chunks->next)
			{
				chunk_size = chunks->nb - chunks->next->nb;
				if (new_chunk_size > 0)
					chunk_size = new_chunk_size;
			}
			else if (!chunks->next)
			{
				chunk_size = chunks->nb;
				if (new_chunk_size > 0)
					chunk_size = new_chunk_size;
//				printf("\nLAST CHUNK - > chunk_size = %d\n", chunk_size);
			}

//			printf("------> b chunk_size from beggining OF LOOP= %d\n", chunk_size);

			if (chunk_size == 1)
				pa(a, b, 1);
			else if (chunk_size == 2)
			{
				if ((*b)->next && (*b)->nb < (*b)->next->nb)
					sa_sb(b, 'b', 1);
				while ((*b) && chunk_size)
				{
					pa(a, b, 1);
					chunk_size--;
//					printf("ENTERED pa, CHUNKS == 2, new_chunk_size = 0  and chunk_size = %d\n", chunk_size);
				}
				new_chunk_size = 0;
			}
			else if (chunk_size >= 3)
			{
				if ((saved_b = save_stack_to_array(b, chunk_size)) == NULL)
					return ;

		///test
/*				int i = 0;
				while (saved_b[i])
				{
					printf("saved b = %s\n", saved_b[i]);
					i++;
				}
				printf("\n---------------------------------------------------\n\n");
		///test*/

				if ((sorted_b = sort_array(&saved_b[0])) == NULL)
					return ;
				if ((mid_nb_b = find_mid_nb(sorted_b)) == -1)
					return ;

		///test
/*				i = 0;
				while (sorted_b[i])
				{
					printf("sorted b = %s\n", sorted_b[i]);
					i++;
				}
				printf("\n-> mid_nb_b = %d\n", mid_nb_b);
				printf("\n---------------------------------------------------\n\n");
		///test*/

		//// test
		/*		t_lst *tmp;
				t_lst *btmp;
				t_lst *chunk_tmp;
				btmp = (*b);
				tmp = (*a);
				chunk_tmp = chunks;
				while (tmp)
				{
					printf("a = %d		", tmp->nb);
					tmp = tmp->next;
					if (btmp)
					{
						printf("		b = %d\n", btmp->nb);
						btmp = btmp->next;
					}
				}
				while (btmp)
				{
					printf("				b = %d\n", btmp->nb);
					btmp = btmp->next;
				}
				while (chunk_tmp)
				{
					printf(">>> chunks = %d\n", chunk_tmp->nb);
					chunk_tmp = chunk_tmp->next;
				}
				printf("\n---------------------------------------------------\n");
		///test*/

				if (chunk_is_sort((*b), -1, chunk_size) == 0)
				{
//					printf("CHUNK IS SORTED - PA\n");
					while (chunk_size--)
						pa(a, b, 1);
					new_chunk_size = 0;
				}
				else if (chunk_is_sort((*b), -1, chunk_size) == -1 && chunks->next)
				{
//					printf("|||chunks size = %d\n", chunk_size);
//					printf("CHUNK IS NOT SORTED\n");
					if ((ret = midpoint_sort_b(a, b, mid_nb_b, chunk_size)) > 0)
					{
						new_chunk_size = ret;
					//	if (ret == 2 || ret == 3)
					//		new_chunk_size = ret - 1;
					}
					else
						new_chunk_size = 0;
//					printf("NEW CHUNK SIZE = %d\n", new_chunk_size);
				//	printf("|||chunks->nb = %d\n", chunks->nb);
				}
				else
				{
					if ((ret = midpoint_sort_b_last(a, b, mid_nb_b, chunk_size)) > 0)
						new_chunk_size = ret;
					else
						new_chunk_size = 0;
				}
			//

				ft_freetab(sorted_b);
			}
		//// test
/*				t_lst *tmp;
				t_lst *btmp;
				t_lst *chunk_tmp;
				btmp = (*b);
				tmp = (*a);
				chunk_tmp = chunks;
				while (tmp)
				{
					printf("a = %d		", tmp->nb);
					tmp = tmp->next;
					if (btmp)
					{
						printf("		b = %d\n", btmp->nb);
						btmp = btmp->next;
					}
				}
				while (btmp)
				{
					printf("				b = %d\n", btmp->nb);
					btmp = btmp->next;
				}
				while (chunk_tmp)
				{
					printf(">>> chunks = %d\n", chunk_tmp->nb);
					chunk_tmp = chunk_tmp->next;
				}
				if (!btmp)
					printf("B IS EMPTY\n");
				printf("\n---------------------------------------------------\n");
		///test*/
			if (new_chunk_size == 0)
				chunks = chunks->next;
//			printf("\n\nLOOP AGAIN with NEW chunk size = %d\nif size == 0, loop with chunk->next nb\n", new_chunk_size);
		}
	}
/*	t_lst *tmp;
	tmp = (*a);
	while (tmp)
	{
		printf("a = %d\n", tmp->nb);
		tmp = tmp->next;
	}*/
}


