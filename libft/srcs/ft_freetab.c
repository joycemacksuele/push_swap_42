/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 14:26:41 by jle-corr          #+#    #+#             */
/*   Updated: 2021/03/31 17:08:08 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_freetab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
	//	free(tab[i]);
	//	tab[i] = NULL;
		ft_strdel(&tab[i]);
	}
	ft_strdel(&tab[i]);
	//free(tab[i]);
//	tab[i] = NULL;
	return (NULL);
}
