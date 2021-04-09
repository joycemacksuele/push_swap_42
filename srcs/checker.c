/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 00:08:21 by jfreitas          #+#    #+#             */
/*   Updated: 2021/04/02 00:00:44 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_operations_on_stacks(char *line, t_lst **a, t_lst **b)
{
	if (ft_strcmp(line, "sa") == 0)
		sa_sb(a, 'a', 0);
	else if (ft_strcmp(line, "sb") == 0)
		sa_sb(b, 'b', 0);
	else if (ft_strcmp(line, "ss") == 0)
		ss(a, b, 0);
	else if (ft_strcmp(line, "pa") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(line, "pb") == 0)
		pb(a, b, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ra_rb(a, 'a', 0);
	else if (ft_strcmp(line, "rb") == 0)
		ra_rb(b, 'b', 0);
	else if (ft_strcmp(line, "rr") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(line, "rra") == 0)
		rra_rrb(a, 'a', 0);
	else if (ft_strcmp(line, "rrb") == 0)
		rra_rrb(b, 'b', 0);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(a, b, 0);
}
/*
 * If after executing the instructions, stack a is actually sorted AND b is
 * empty, then checker must display "OK" followed by a ’\n’ on the standard
 * output. In every other case, checker must display "KO" followed by a ’\n’
 * on the standard output.
 */

void	create_lists(char *opt, char **av)
{
	t_list	*operations;
	t_lst	*a;
	t_lst	*b;
	char	**lines;

	operations = NULL;
	a = NULL;
	b = NULL;
	lines = ft_split(opt, ' ');
//	operations = (t_list *)malloc(sizeof(t_list));
//	if (!operations)
//		return ;
	operations = create_list(lines);
/*	while (operations)
	{
		printf("operation = %s\n", (char *)operations->content);
		operations = operations->next;
	}*/
	if (is_sort(av, -1) == -1)
		a = create_lst(&av[1]);

	while (*lines != NULL)
	{
		run_operations_on_stacks(*lines, &a, &b);
		lines++;
	//	operations = operations->next;
	}
	if (lst_is_sort(a ,0) == 0 && !b)
		ft_putstr_fd("OK\n", 1);
//	else if (lst_is_sort(a ,0) == -1)
	else
		ft_putstr_fd("KO\n", 1);
/*	while (a)
	{
		printf("a = %d\n", a->nb);
		a = a->next;
	}*/
	//free_list(&operations);
	ft_lstclear(&operations, &free_list);
	//lstclear(&a, &free_lst);
	//stclear(&b, &free_lst);
	free_lst(&a);
	free_lst(&b);
	ft_freetab(lines);
}

int	check_operations(char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		return (0);
	else if (ft_strcmp(line, "sb") == 0)
		return (0);
	else if (ft_strcmp(line, "ss") == 0)
		return (0);
	else if (ft_strcmp(line, "pa") == 0)
		return (0);
	else if (ft_strcmp(line, "pb") == 0)
		return (0);
	else if (ft_strcmp(line, "ra") == 0)
		return (0);
	else if (ft_strcmp(line, "rb") == 0)
		return (0);
	else if (ft_strcmp(line, "rr") == 0)
		return (0);
	else if (ft_strcmp(line, "rra") == 0)
		return (0);
	else if (ft_strcmp(line, "rrb") == 0)
		return (0);
	else if (ft_strcmp(line, "rrr") == 0)
		return (0);
	else
		return (-1);
}

int	read_operations(char **av)
{
	char	*line;
	char	*opt;
	int		ret_gnl;

	line = NULL;
	opt = ft_strdup("");
	//ret_gnl = 0;
	while ((ret_gnl = get_next_line(0, &line)) > 0)
	{
		if (check_operations(line) == -1)
		{
			free(opt);
			free(line);
			return (-1);
		}
		opt = ft_strjoin(opt, line);
		opt = ft_strjoin(opt, " ");
		free(line);
	}
	ft_strdel(&line);
	if (ret_gnl == 0)
		create_lists(opt, av);
	ft_strdel(&opt);
	if (ret_gnl == -1)
	{
		printf("ret gnl = %d\n", ret_gnl);
		return (-1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac <= 1)
		return (-1);
	else if (ac >= 2)
	{
		if (not_int(av) == -1 || find_doubles(av) == -1 ||
			read_operations(av) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
	}
	return (0);
}
