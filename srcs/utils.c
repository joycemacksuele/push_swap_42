/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:56:28 by jfreitas          #+#    #+#             */
/*   Updated: 2021/03/28 18:00:54 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
