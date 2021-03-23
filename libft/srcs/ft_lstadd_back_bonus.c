
#include "../includes/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*alst);
	if (!new)
		return ;
	if (!last)
		ft_lstadd_front(alst, new);
	else
		last->next = new;
}
