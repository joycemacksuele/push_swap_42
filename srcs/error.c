/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:55:21 by jfreitas          #+#    #+#             */
/*   Updated: 2021/06/10 18:04:44 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * In case of error, you must display Error followed by a ’\n’ on the standard
 * error. Errors include for example:
 *
 * push_swap and checker:
 * 1. some arguments aren’t integers
 * 2. some arguments are bigger than an integer
 * 3. there are duplicates.
 *
 * checker:
 * 4. an instruction don’t exist and/or is incorrectly formatted.
 */

int	find_doubles(char **av)
{
	int	i;
	int	j;
	int	nbi;
	int	nbj;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			nbi = ft_atoi(av[i]);
			nbj = ft_atoi(av[j]);
			if (nbi == nbj)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	not_int(char **av)
{
	int			i;
	size_t		j;
	long long	nb;

	i = 1;
	while (av[i])
	{
		j = -1;
		nb = ft_long_long_atoi(av[i]);
		while (++j < ft_strlen(av[i]))
		{
			if ((av[i][0] == '-' || av[i][0] == '+') && av[i][1])
				j++;
			if (av[i][j] && !(ft_isdigit(av[i][j])))
				return (-1);
		}
		if (nb > 2147483647 || nb < -2147483648 || ft_strlen(av[i]) > 11)
		{
			printf("bigger than int\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

/*
 * Optional error message:
 *	ft_putstr_fd("More than 1 signed integer argument needed!\n", 2);
 */

int	handle_wrong_ac(int ac)
{
	if (ac <= 1)
	{
		return (-1);
	}
	return (0);
}
