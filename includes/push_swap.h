/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 02:13:33 by jfreitas          #+#    #+#             */
/*   Updated: 2021/03/19 02:23:16 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list//or use t_lit from libft??
{
	int				data;// here it would be void *content, so -> list->&content ??
	struct s_list	*next;
}					t_list;

/*
 * push_swap
 */
void	push_swap(t_list **a, t_list **b, int ac);

/*
 * checker
 */
void	checker(t_list **a, t_list **b, int ac);

#endif
