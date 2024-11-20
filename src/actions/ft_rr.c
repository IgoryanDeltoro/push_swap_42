#include "../../includes/push_swap.h"

void	ft_rr(t_list **lst_a, t_list **lst_b)
{
	if (!(*lst_a) || !(*lst_b) || !lst_a || !lst_b)
		return ;
    printf("rr\n");
	ft_ra(lst_a);
	ft_rb(lst_b);
}
