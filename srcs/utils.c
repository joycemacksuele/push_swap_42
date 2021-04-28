/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:56:28 by jfreitas          #+#    #+#             */
/*   Updated: 2021/04/27 02:29:38 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (a_or_b);
}

char	**save_stack_to_array(t_lst **a_or_b, int len)
{
	char	**saved;
	char	*itoa;
	t_lst	*tmp;
	int		i;

	saved = (char **)malloc(sizeof(char *) * (len + 1));
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
		//free(tmp);
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
 *
 * @args:
 *		char **av: the arguments of the program call.
 * @return:
 *		int: 0 is it's sorted and -1 if it's not sorted.
 */

int	is_sort(char **av, int error)
{
	int	i;

	i = 0;
	(void)error;
	if (av)
	{
		if (av[0] && (ft_strcmp(av[0], "./push_swap") == 0 ||
			ft_strcmp(av[0], "./checker") == 0))
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
