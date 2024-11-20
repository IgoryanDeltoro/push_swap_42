#include "../../includes/push_swap.h"

void	ft_rb(t_list **lst_b)
{
	t_list	*first;
	t_list	*temp;

	if (!(*lst_b) || !(*lst_b)->next)
		return ;
	printf("rb\n");
	first = *lst_b;
	*lst_b = (*lst_b)->next;
	temp = *lst_b;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
}
