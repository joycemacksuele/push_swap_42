/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:56:28 by jfreitas          #+#    #+#             */
/*   Updated: 2021/06/21 20:54:48 by whoami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bigger_nbr_and_index(t_lst **head, t_lst *tmp, int index, int i)
{
	(*head) = tmp->next;
	index = i;
	return (index);
}

/*
 * It searches for the biggest number and it's index from a given list.
 */

int	search_bigger_number(t_lst **head, int checker, int bigger1)
{
	t_lst	*tmp;
	int		bigger_index;
	int		i;

	tmp = (*head);
	bigger_index = 0;
	i = 1;
	while (tmp != NULL)
	{
		if (checker == 0 && (*head)->nb == bigger1)
			(*head) = (*head)->next;
		if (tmp->next && (*head)->nb < tmp->next->nb)
		{
			if (checker == 0 && tmp->next->nb != bigger1)
				bigger_index = bigger_nbr_and_index(head, tmp, bigger_index, i);
			else if (checker == -1)
				bigger_index = bigger_nbr_and_index(head, tmp, bigger_index, i);
		}
		tmp = tmp->next;
		i++;
	}
	return (bigger_index);
}

/*
 * Used by the algorithms for when the input numbers are from 100 to 500, so
 * later this sorted array of arrays can be used to find its middle number.
 */

char	**sort_array(char **a_or_b)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (!a_or_b)
		return (NULL);
	while (is_sort(&a_or_b[0], 0) == -1)
	{
		i = 0;
		while (a_or_b[i] != NULL)
		{
			if (a_or_b[i + 1] && ft_atoi(a_or_b[i]) > ft_atoi(a_or_b[i + 1]))
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
	return (a_or_b);
}

/*
 * Used by the algorithms for when the input numbers are from 100 to 500, so
 * later this array of arrays can be sorted in orther to find its middle number.
 */

char	**save_stack_to_array(t_lst **a_or_b, int len)
{
	char	**saved;
	char	*itoa;
	t_lst	*tmp;
	int		i;

	if (!(saved = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	itoa = NULL;
	tmp = (*a_or_b);
	i = 0;
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
	}
	else
		return (NULL);
	return (saved);
}

/*
 * Looping av to check if the numbers of the arguments are sorted or not.
 * Obs.: atoi can be used because if has already passed the error functions,
 * so if itgot here, it means that the arguments are indeed not duplicated
 * signed intergers.
 */

int	is_sort(char **av, int error)
{
	int	i;

	i = 0;
	(void)error;
	if (av)
	{
		if (av[0] && (ft_strcmp(av[0], "./push_swap") == 0
				|| ft_strcmp(av[0], "./checker") == 0))
			i = 1;
		while (av[i])
		{
			if (av[i + 1] && av[i] && ft_atoi(av[i]) > ft_atoi(av[i + 1]))
				return (-1);
			i++;
		}
	//	if (error == -1)
			//ft_putstr_fd("Numbers are already sorted!\n", 2);
	}
	return (0);
}
