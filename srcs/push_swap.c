/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfreitas <jfreitas@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 00:08:21 by jfreitas          #+#    #+#             */
/*   Updated: 2021/04/18 03:32:09 by jfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_operations_on_stdout(char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(NULL, 1, NULL);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(NULL, 1, NULL);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(NULL, NULL, 1, NULL);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(NULL, NULL, 1, NULL);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(NULL, NULL, 1, NULL);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(NULL, 1, NULL);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(NULL, 1, NULL);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(NULL, NULL, 1, NULL);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(NULL, 1, NULL);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(NULL, 1, NULL);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(NULL, NULL, 1, NULL);
}

void	operations_corrector(t_list **operations)
{
	t_list	*op_tmp;
	t_list	*last;

	op_tmp = (*operations);
	last = ft_lstlast((*operations));
	while (op_tmp)
	{
	//	printf("op = %s", op_tmp->content);
		if (op_tmp->next)
		{
		/*	if (ft_strcmp(op_tmp->content, "sa\n") == 0)
			{
				if (ft_strcmp(op_tmp->next->content, "sa\n") == 0)
					op_tmp = op_tmp->next;
				else if (ft_strcmp(op_tmp->next->content, "sb\n") == 0)
					ss(NULL, NULL, 1, NULL);
				else
					write_operations_on_stdout(op_tmp->content);
		//		printf("----\n");
			}
			else if (ft_strcmp(op_tmp->content, "sb\n") == 0)
			{
				if (ft_strcmp(op_tmp->next->content, "sb\n") == 0)
					op_tmp = op_tmp->next;
				else if (ft_strcmp(op_tmp->next->content, "sa\n") == 0)
					ss(NULL, NULL, 1, NULL);
				else
					write_operations_on_stdout(op_tmp->content);
		//		printf("----\n");
			}
			else if (ft_strcmp(op_tmp->content, "pa\n") == 0)
			{
				if (ft_strcmp(op_tmp->next->content, "pb\n") == 0)
					op_tmp = op_tmp->next;
				else
					write_operations_on_stdout(op_tmp->content);
		//		printf("----\n");
			}
			else if (ft_strcmp(op_tmp->content, "pb\n") == 0)
			{
				if (ft_strcmp(op_tmp->next->content, "pa\n") == 0)
					op_tmp = op_tmp->next;
				else
					write_operations_on_stdout(op_tmp->content);
		//		printf("----\n");
			}
			else if (ft_strcmp(op_tmp->content, "ra\n") == 0)
			{
				if (ft_strcmp(op_tmp->next->content, "rb\n") == 0)
					rr(NULL, NULL, 1, NULL);
				else if (op_tmp->next->next && op_tmp->next->next->content &&
					ft_strcmp(op_tmp->next->content, "rr\n") == 0)
				{
					while (ft_strcmp(op_tmp->next->content, "rr\n") == 0)
					{
						rr(NULL, NULL, 1, NULL);
						op_tmp = op_tmp->next;
					}
					if (ft_strcmp(op_tmp->next->next->content, "rb\n") == 0)
						rr(NULL, NULL, 1, NULL);
				}
				else if (ft_strcmp(op_tmp->next->content, "rra\n") == 0)
				{
		//			printf("op_tmp->next->next->content = %s\n", op_tmp->next->next->content);
					op_tmp = op_tmp->next;
				}
				else
					write_operations_on_stdout(op_tmp->content);
		//		printf("----\n");
			}
			else if (ft_strcmp(op_tmp->content, "rb\n") == 0)
			{
				if (ft_strcmp(op_tmp->next->content, "ra\n") == 0)
					rr(NULL, NULL, 1, NULL);
				else if (op_tmp->next->next && op_tmp->next->next->content &&
					ft_strcmp(op_tmp->next->content, "rr\n") == 0)
				{
					while (ft_strcmp(op_tmp->next->content, "rr\n") == 0)
					{
						rr(NULL, NULL, 1, NULL);
						op_tmp = op_tmp->next;
					}
					if (ft_strcmp(op_tmp->next->next->content, "ra\n") == 0)
						rr(NULL, NULL, 1, NULL);
				}
				else if (ft_strcmp(op_tmp->next->content, "rrb\n") == 0)
					op_tmp = op_tmp->next;
				else
					write_operations_on_stdout(op_tmp->content);
		//		printf("----\n");
			}
			else if (ft_strcmp(op_tmp->content, "rr\n") == 0)
			{
				if (ft_strcmp(op_tmp->next->content, "rrr\n") == 0)
					op_tmp = op_tmp->next;
				else if ((ft_strcmp(op_tmp->next->content, "rra\n") == 0 &&
					ft_strcmp(op_tmp->next->next->content, "rrb\n") == 0) ||
					(ft_strcmp(op_tmp->next->content, "rrb\n") == 0 &&
					ft_strcmp(op_tmp->next->next->content, "rra\n") == 0))
					op_tmp = op_tmp->next;
				else
					write_operations_on_stdout(op_tmp->content);
		//		printf("----\n");
			}
			else if (ft_strcmp(op_tmp->content, "rra\n") == 0)
			{
				if (ft_strcmp(op_tmp->next->content, "rrb\n") == 0)
					rrr(NULL, NULL, 1, NULL);
				else if (op_tmp->next->next->content &&
					ft_strcmp(op_tmp->next->content, "rrr\n") == 0)
				{
					while (ft_strcmp(op_tmp->next->content, "rrr\n") == 0)
					{
						rrr(NULL, NULL, 1, NULL);
						op_tmp = op_tmp->next;
					}
					if (ft_strcmp(op_tmp->next->next->content, "rrb\n") == 0)
						rr(NULL, NULL, 1, NULL);
				}
				else if (ft_strcmp(op_tmp->next->content, "rb\n") == 0)
					op_tmp = op_tmp->next;
				else
					write_operations_on_stdout(op_tmp->content);
		//		printf("----\n");
			}
			else if (ft_strcmp(op_tmp->content, "rrb\n") == 0)
			{
				if (ft_strcmp(op_tmp->next->content, "rra\n") == 0)
					rrr(NULL, NULL, 1, NULL);
				else if (op_tmp->next->next->content &&
					ft_strcmp(op_tmp->next->content, "rrr\n") == 0)
				{
					while (ft_strcmp(op_tmp->next->content, "rrr\n") == 0)
					{
						rrr(NULL, NULL, 1, NULL);
						op_tmp = op_tmp->next;
					}
					if (ft_strcmp(op_tmp->next->next->content, "rra\n") == 0)
						rr(NULL, NULL, 1, NULL);
				}
				else if (ft_strcmp(op_tmp->next->content, "ra\n") == 0)
					op_tmp = op_tmp->next;
				else
					write_operations_on_stdout(op_tmp->content);
		//		printf("----\n");
			}
			else if (ft_strcmp(op_tmp->content, "rrr\n") == 0)
			{
				if (ft_strcmp(op_tmp->next->content, "rr\n") == 0)
					op_tmp = op_tmp->next;
				else if ((ft_strcmp(op_tmp->next->content, "ra\n") == 0 &&
					ft_strcmp(op_tmp->next->next->content, "rb\n") == 0) ||
					(ft_strcmp(op_tmp->next->content, "rb\n") == 0 &&
					ft_strcmp(op_tmp->next->next->content, "ra\n") == 0))
					op_tmp = op_tmp->next;
				else*/
					write_operations_on_stdout(op_tmp->content);
		//		printf("----\n");
		//	}
		}
		op_tmp = op_tmp->next;
	}
	write_operations_on_stdout(last->content);
}

void	pick_algo(t_lst **a, t_lst **b, int ac)
{
	t_list *operations;
	t_list	**operations_tmp;

	operations = NULL;

	operations_tmp = &operations;
	if (ac == 2 || ac == 3)
		sort_max_3(a, &operations);
	else if (ac <= 20)
		sort_max_12(a, b, &operations);
	else
		sort_max_100(a, b, &operations);
//	else
//		sort_max_500(a, b);
	//	sort_max_500(a, b);


	operations_corrector(&operations);
/// test operations
	printf("============\n");
/*	while ((*operations_tmp))
	{
		printf("%s", (*operations_tmp)->content);
		(*operations_tmp) = (*operations_tmp)->next;
	}
/// test operations
*/
	ft_lstclear(&operations, &free_list);

///// test
/*	printf("------------ Sorted list a ------------\n");

	printf("len a = %d\n", lstlen(a));
	if ((*a))
		printf("a\n-\n");
	while (*a)
	{
		printf("%d\n", (int)(*a)->nb);
		(*a) = (*a)->next;
	}

	printf("------------ Sorted list b ------------\n");

	printf("len b = %d\n", lstlen(b));
	if (!(*b))
		printf("List b is empty\n");
	else
		printf("b\n-\n");
	while (*b)
	{
		printf("%d\n", (int)(*b)->nb);
		(*b) = (*b)->next;
	}*/

///// test
}

int	main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;

	g_count_operations = 0;
	a = NULL;
	b = NULL;
	if (handle_wrong_ac(ac) == -1)
		return (-1);
	else if (ac >= 2)
	{
		if (not_int(av) == -1 || find_doubles(av) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		if (is_sort(av, -1) == -1)
		{
			a = create_lst(&av[1]);
			pick_algo(&a, &b, ac - 1);
		}
		free_lst(&a);
		free_lst(&b);
	}
	printf("NUMBER OF REGISTERS BEFORE = %d\n", g_count_operations);
	printf("NUMBER OF REGISTERS AFTER = %d\n", g_count_operations_after);
	return (0);
}
