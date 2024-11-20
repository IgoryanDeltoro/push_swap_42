/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:46:24 by igoryan           #+#    #+#             */
/*   Updated: 2024/11/15 18:41:24 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

#include "../../includes/push_swap.h"

void	ft_rrb(t_list **lst_b)
{
	t_list	*last;
	t_list	*before_last;
	
	if (!(*lst_b) || !(*lst_b)->next)
		return ;
    printf("rrb\n");
	last = *lst_b;
	before_last = NULL;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *lst_b;
	*lst_b = last;
}