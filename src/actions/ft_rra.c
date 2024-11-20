/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:48:26 by igoryan           #+#    #+#             */
/*   Updated: 2024/11/15 18:41:15 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rra(t_list **lst_a)
{
	t_list	*last;
	t_list	*before_last;
	
	if (!(*lst_a) || !(*lst_a)->next)
		return ;
    printf("rra\n");
	last = *lst_a;
	before_last = NULL;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *lst_a;
	*lst_a = last;
}
