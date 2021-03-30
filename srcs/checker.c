/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 00:08:21 by jfreitas          #+#    #+#             */
/*   Updated: 2021/03/30 03:05:43 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_operations(t_list **operations)
{
	t_list	*tmp;

	tmp = (*operations);
	while ((*operations))
	{
		if (tmp && tmp->content)
		{
			if (ft_strcmp((char *)tmp->content, "sa\n") == 0)
				return (0);
			else if (ft_strcmp((char *)tmp->content, "sb") == 0)
				return (0);
			else if (ft_strcmp((char *)tmp->content, "ss") == 0)
				return (0);
			else if (ft_strcmp((char *)tmp->content, "pa") == 0)
				return (0);
			else if (ft_strcmp((char *)tmp->content, "pb") == 0)
				return (0);
			else if (ft_strcmp((char *)tmp->content, "ra") == 0)
				return (0);
			else if (ft_strcmp((char *)tmp->content, "rb") == 0)
				return (0);
			else if (ft_strcmp((char *)tmp->content, "rr") == 0)
				return (0);
			else if (ft_strcmp((char *)tmp->content, "rra") == 0)
				return (0);
			else if (ft_strcmp((char *)tmp->content, "rrb") == 0)
				return (0);
			else if (ft_strcmp((char *)tmp->content, "rrr") == 0)
				return (0);
			tmp = tmp->next;
		}
	}

	printf("|x| = |%s|\n", (char *)tmp->content);
	return (-1);
}
/*
 * If after executing the instructions, stack a is actually sorted AND b is
 * empty, then checker must display "OK" followed by a ’\n’ on the standard
 * output. In every other case, checker must display "KO" followed by a ’\n’
 * on the standard output.
 */

t_list	*read_operations(void)
{
	t_list	*operations;
	t_list	*tmp;
	int		ret_gnl;

	operations = (t_list *)malloc(sizeof(t_list));
	tmp = NULL;
	while ((ret_gnl = get_next_line(0, (char**)&operations->content)) == 1)
	{
		printf("ret gnl = %d\n", ret_gnl);
		operations = create_list_with_operations(operations->content);

	//	tmp = ft_lstnew(operations->content);
	//	ft_lstadd_back(&operations, tmp);
	}
	if (ret_gnl == 0)
	{

	//	error handling();
	//	run_operations on stack();
		printf("ret gnl = %d\n", ret_gnl);
		return (operations);
	}
	if (ret_gnl == -1)
	{
		printf("ret gnl = %d\n", ret_gnl);
		return (NULL);
	}
	return (operations);
}

int	main(int ac, char **av)
{
//	t_lst	*a;
//	t_lst	*b;
	t_list	*operations;

//	a = NULL;
//	b = NULL;
	operations = NULL;
	if (ac <= 1)
		return (-1);
	else if (ac >= 2)
	{
		if (not_int(av) == -1 || find_doubles(av) == -1 ||
			(operations = read_operations()) == NULL)
		{
			free_list(&operations);
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		else if (check_operations(&operations) == -1)
		{
			free_list(&operations);
			ft_putstr_fd("KO\n", 2);
			return (-1);
		}
		while (operations)
		{
			printf("%s\n", (char *)operations->content);
			operations = operations->next;
		}
	}
	return (0);
}
