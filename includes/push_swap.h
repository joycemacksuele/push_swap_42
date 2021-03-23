/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 02:13:33 by jfreitas          #+#    #+#             */
/*   Updated: 2021/03/23 02:04:16 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# include <unistd.h>
# include <stdlib.h>

/*typedef struct s_list//or use t_lit from libft??
{
	int				data;// here it would be void *content, so -> list->&content ??
}					t_list;*/

/*
 * push_swap
 */
void	push_swap(t_list **a, t_list **b, int ac);
int		not_int(char **av);
int		find_doubles(char **av);
/* push_swap list */
t_list	*create_list(char **av);
void	free_list_a(t_list **a);

/*
 * checker
 */
void	checker(t_list **a, t_list **b, int ac);

#endif
